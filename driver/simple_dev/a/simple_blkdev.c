#include <linux/init.h>
#include <linux/module.h>
#include <linux/blkdev.h>

#define SIMP_BLKDEV_DEVICEMAJOR	COMPAQ_SMART2_MAJOR
#define SIMP_BLKDEV_DISKNAME	"simp_blkdev"
#define SIMP_BLKDEV_BYTES	(16 * 1024 * 1024)

static struct request_queue *simp_blkdev_queue;
static struct gendisk *simp_blkdev_disk;

static void simp_blkdev_do_request(struct request_queue *q);

struct block_device_operations simp_blkdev_fops = {
	.owner = THIS_MODULE,
};

unsigned char simp_blkdev_data[SIMP_BLKDEV_BYTES];

static int __init
simp_blkdev_init(void)
{
	int ret;

	simp_blkdev_queue = blk_init_queue(simp_blkdev_do_request, NULL);
	if (!simp_blkdev_queue) {
		ret = -ENOMEM;
		goto err_init_queue;
	}

	simp_blkdev_disk = alloc_disk(1);
	if (!simp_blkdev_disk) {
		ret = -ENOMEM;
		goto err_alloc_disk;
	}
	
	strcpy(simp_blkdev_disk->disk_name, SIMP_BLKDEV_DISKNAME);
	simp_blkdev_disk->major = SIMP_BLKDEV_DEVICEMAJOR;
	simp_blkdev_disk->first_minor = 0;
	simp_blkdev_disk->fops = &simp_blkdev_fops;
	simp_blkdev_disk->queue = simp_blkdev_queue;
	set_capacity(simp_blkdev_disk, SIMP_BLKDEV_BYTES >> 9);
	add_disk(simp_blkdev_disk);
	return 0;

err_alloc_disk:
	blk_cleanup_queue(simp_blkdev_queue);
err_init_queue:
	return ret;
}

static void __exit
simp_blkdev_exit(void)
{
	del_gendisk(simp_blkdev_disk);
	put_disk(simp_blkdev_disk);
	blk_cleanup_queue(simp_blkdev_queue);
}

module_init(simp_blkdev_init);
module_exit(simp_blkdev_exit);

static void simp_blkdev_do_request(struct request_queue *q)
{
	struct request *req;
	//while ((req = elv_next_request(q)) != NULL) {
	while ((req = blk_fetch_request(q)) != NULL) {
		//if ((req->__sector + req->current_nr_sectors) << 9
		if ((req->__sector + req->__data_len) << 9
			> SIMP_BLKDEV_BYTES) {
			printk(KERN_ERR SIMP_BLKDEV_DISKNAME
				":bad request: block=%llu, count=%u\n",
				(unsigned long long)req->__sector,
				req->__data_len);
			end_request(req, 0);
			continue;
		}

		switch (rq_data_dir(req)) {
		case READ:
			memcpy(req->buffer,
				simp_blkdev_data + (req->sector << 9),
				req->current_nr_sectors << 9);
			end_request(req, 1);
			break;
		case WRITE:
			memcpy(simp_blkdev_data + (req->sector << 9),
				req->buffer, req->current_nr_sectors << 9);
			end_request(req, 1);
			break;
		default:
			/* No default because rq_data_dir(req) is 1 bit */
			break;
		}
	}
}

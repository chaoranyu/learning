#include <linux/init.h>
#include <linux/module.h>

#define SIMPLE_BLKDEV_DEVICEMAJOR	COMPAQ_SMART2_MAJOR
#define SIMPLE_BLKDEV_DISKNAME		"simp_blkdev"
#define SIMPLE_BLKDEV_BYTES		(16 * 1024 * 1024)

static struct request_queue *simp_blkdev_queue;
static struct gendisk *simp_blkdev_disk;

static void simp_blkdev_do_request(struct request_queue *q);

struct block_device_operations simp_blkdev_fops = {
	.owner = THIS_MODULE,
};


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
	
	strcpy(simp_blkdev_disk->diskname, SIMP_BLKDEV_DISKNAME);
	simp_blkdev_disk->major = SIMP_BLKDEV_MAJOR;
	simp_blkdev_disk->first_minor = 0;
	simp_blkdev_disk->fops = simple_blkdev_fops;
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
	put(simp_blkdev_disk);
	blk_cleanup_queue(simp_blkdev_queue);
}

module_init(simp_blkdev_init);
module_exit(simp_blkdev_exit);

static void simp_blkdev_do_request(struct request_queue *q)
{
}

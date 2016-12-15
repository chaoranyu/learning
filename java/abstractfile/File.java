import java.util.*;

public class File extends AbstractFile {
    public File(String name) {
        this.name = name;
    }
//文件并没有添加的能力，它只是一个单独的个体
    public boolean addChild(AbstractFile file) {
        return false;
    }
//对于文件本身，已经是叶子节点了，所以也无删除子文件的功能
    public boolean removeChild(AbstractFile file) {
        return false;
    }

    // 由于File已经是叶子节点了，所以就不存在集合这一说，所以这个方法返回的是空值
    public List<AbstractFile> getChildren() {
        return null;
    }
}

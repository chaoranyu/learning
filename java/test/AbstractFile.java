import java.util.*;    //添加引用

public abstract class AbstractFile {
    protected String name; // 定义name字段

    public void printName() {
        System.out.println(name);
    }

    // 通常都用add和remove方法来提供增加或移除树叶或树枝的功能
    public abstract boolean addChild(AbstractFile file); // 增加

    public abstract boolean removeChild(AbstractFile file); // 移除
    // 一个集合，存放摘要文件的子文件的对象

    public abstract List<AbstractFile> getChildren();
}

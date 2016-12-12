import java.util.*;    //添加引用

public class Folder extends AbstractFile {

    private List<AbstractFile> childList ;

    public Folder(String name) {
        this.name = name;
        //用来建立一个集合保存子文件
        this.childList = new ArrayList<AbstractFile>();
    }
    //添加子文件
    public boolean addChild(AbstractFile file) {
        return childList.add(file);
    }
    //删除子文件
    public boolean removeChild(AbstractFile file) {
        return childList.remove(file);
    }

    // 子类的返回类型应该和父类的定义保持一致
    public List<AbstractFile> getChildren() {
        return childList;
    }

}

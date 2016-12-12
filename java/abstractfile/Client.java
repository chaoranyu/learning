import java.util.*;    //添加引用

public class Client {
    public static void main(String[] args) {
        // TODO 自动生成的方法存根
        // 构造一个树形的文件、目录结构
        AbstractFile rootFolder = new Folder("c:");
        AbstractFile compositeFolder = new Folder("composite");
        AbstractFile windowsFolder = new Folder("windows");
        AbstractFile file = new File("TestComposite.java");

        rootFolder.addChild(compositeFolder);
        rootFolder.addChild(windowsFolder);
        compositeFolder.addChild(file);
        // 打印目录文件树
        printTree(rootFolder);
    }

    private static void printTree(AbstractFile ifile) {
        ifile.printName();
        List<AbstractFile> children = ifile.getChildren();
        if (children == null)
            return;
        for (AbstractFile file : children) {
            printTree(file); // 打印方法的调用
        }
    }
}

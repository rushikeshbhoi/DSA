import java.util.*;
import java.io.*;

class Program220
{
    public static void main(String arg[]) throws Exception
    {
        Scanner sobj = new Scanner(System.in);

        System.out.println("Enter the name of file :");
        String FileName = sobj.nextLine();

    try
    {
        File fobj = new File(FileName);

        boolean bret = false;

        bret = fobj.exists();
        if(bret)    // if(bret == true)
        {
            System.out.println("Name of file is : "+fobj.getName());
            System.out.println("Absolute path of file is : "+fobj.getAbsolutePath());
            System.out.println("File size is : "+fobj.length());
            System.out.println("we can read from file "+fobj.canRead());
            System.out.println("we can write into file "+fobj.canWrite());
        }
    }

    catch(Exception obj)
    {
        System.out.println("Exception occurred");
    }

    }
}
import java.util.*;
import java.io.*;

class Program218
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

        bret = fobj.createNewFile();

        if(bret == true)
        {
            System.out.println("File gets succesfullt created..");
        }
        else
        {
            System.out.println("Unable to create file..");
        }
    }

    catch(IOException obj)
    {
        System.out.println("Exception occurred");
    }
    catch(Exception obj)
    {
        System.out.println("Exception occurred");
    }

    }
}
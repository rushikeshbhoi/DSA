import LB.Matrix;
import java.util.*;

class MyMatrix extends Matrix
{
    public MyMatrix(int A, int B)
    {
        super(A,B);
    }

    public void SummationRow()
    {
        int i = 0, j = 0, iSum = 0;

        for(i = 0; i < Arr.length; i++)
        {
            for(j = 0; j < Arr[i].length; j++)
            {
                iSum = iSum + Arr[i][j];
            }
            System.out.println("Summation of Row is : "+(i+1) + " is : " +iSum);
            iSum = 0;
        }
    }

    public void MaximumRow()
    {
        int i = 0, j = 0, iMax = 0;

        for(i = 0; i < Arr.length; i++)
        {
            iMax = Arr[i][0];

            for(j = 0; j < Arr[i].length; j++)
            {
                if(Arr[i][j] > iMax)
                {
                    iMax = Arr[i][j];
                }
            }
            
            System.out.println("Maximum element from Row no : "+(i+1) + " is : " +iMax);
        }
    }

    public void MinimumRow()
    {
        int i = 0, j = 0, iMin = 0;

        for(i = 0; i < Arr.length; i++)
        {
            iMin = Arr[i][0];
            
            for(j = 0; j < Arr[i].length; j++)
            {
                if(Arr[i][j] < iMin)
                {
                    iMin = Arr[i][j];
                }
            }
            
            System.out.println("Minimum element from Row no : "+(i+1) + " is : " +iMin);
        }
    }

    public int Frequency(int iNo)
    {
        int i = 0, j = 0;
        int iFrequency = 0;

        for(i = 0; i < Arr.length; i++)
        {   
            for(j = 0; j < Arr[i].length; j++)
            {
                if(Arr[i][j] == iNo)
                {
                    iFrequency++;
                }
            }
        }
        return iFrequency;
    }

    public int CountOdd()
    {
        int i = 0, j = 0;
        int iOdd = 0;

        for(i = 0; i < Arr.length; i++)
        {   
            for(j = 0; j < Arr[i].length; j++)
            {
                if((Arr[i][j] % 2) != 0)
                {
                    iOdd++;
                }
            }
        }
        return iOdd;
    }

    public int CountEven()
    {
        int i = 0, j = 0;
        int iEven = 0;

        for(i = 0; i < Arr.length; i++)
        {   
            for(j = 0; j < Arr[i].length; j++)
            {
                if((Arr[i][j] % 2) == 0)
                {
                    iEven++;
                }
            }
        }
        return iEven;
    }

    public void UpdateMatrix()
    {
        int i = 0, j = 0;

        for(i = 0; i < Arr.length; i++)
        {   
            for(j = 0; j < Arr[i].length; j++)
            {
                if((Arr[i][j] % 2) != 0)
                {
                    Arr[i][j] = (Arr[i][j]) + 1;
                }
            }
        }
    }
}

class Program240
{
    public static void main(String Arg[])
    {
        Scanner sobj = new Scanner(System.in);
        int iRow = 0, iCol = 0, iRet = 0;

        System.out.println("Enter number of rows : ");
        iRow = sobj.nextInt();

        System.out.println("Enter number of columns : ");
        iCol = sobj.nextInt();

        
        MyMatrix mobj = new MyMatrix(iRow,iCol);
        
        mobj.Accept();
        mobj.Display();
        
   
        // Function calls

        mobj.UpdateMatrix();

        System.out.println("Updated matrix is : ");
        mobj.Display();

        mobj = null;
        System.gc();
    }
}
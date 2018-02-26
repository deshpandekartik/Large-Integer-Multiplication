import java.util.*;


public class Strassen {

    Random r, r1;

    private static int[][] a = new int[4][4];
    private static int[][] b = new int[4][4];
    private static int[][] c = new int[4][4];

    public static void multiply(int[][] a, int[][] b)
    {
        int i,j;

        for(i=0;i<a.length;i++)
        {
            for(j =0; j<a.length;j++)
            {   c[i][j]=0;
                for(int k = 0;k<a.length;k++)
                {
                    c[i][j] += a[i][k] * b[k][j];
                }
            }
        }
        System.out.println("Matrix multiplication by regular method : ");
        System.out.println();
        for(i=0;i<a.length;i++)
        {
            for(j =0; j<a.length;j++)
            {
                System.out.print(c[i][j] + "  ");
            }
            System.out.println();
        }
    }

    public static int [][] strassen(int [][] a, int [][] b)
	{
		int n = a.length;
		int [][] result = new int[n][n];
		System.out.print(n);
		if(n == 1)
		{
			result[0][0] = a[0][0] * b[0][0];
		}
		else
		{
			int [][] A11 = new int[n/2][n/2];
			int [][] A12 = new int[n/2][n/2];
			int [][] A21 = new int[n/2][n/2];
			int [][] A22 = new int[n/2][n/2];

			int [][] B11 = new int[n/2][n/2];
			int [][] B12 = new int[n/2][n/2];
			int [][] B21 = new int[n/2][n/2];
			int [][] B22 = new int[n/2][n/2];

			divide(a, A11, 0 , 0);
			divide(a, A12, 0 , n/2);
			divide(a, A21, n/2, 0);
			divide(a, A22, n/2, n/2);

			divide(b, B11, 0 , 0);
			divide(b, B12, 0 , n/2);
			divide(b, B21, n/2, 0);
			divide(b, B22, n/2, n/2);

			int [][] P1 = strassen(add(A11, A22), add(B11, B22));
			int [][] P2 = strassen(add(A21, A22), B11);
			int [][] P3 = strassen(A11, sub(B12, B22));
			int [][] P4 = strassen(A22, sub(B21, B11));
			int [][] P5 = strassen(add(A11, A12), B22);
			int [][] P6 = strassen(sub(A21, A11), add(B11, B12));
			int [][] P7 = strassen(sub(A12, A22), add(B21, B22));
			//print(P1);

			int [][] C11 = add(sub(add(P1, P4), P5), P7);
			int [][] C12 = add(P3, P5);
			int [][] C21 = add(P2, P4);
			int [][] C22 = add(sub(add(P1, P3), P2), P6);

			print(C11);
			copy(C11, result, 0 , 0);
			print(result);
			copy(C12, result, 0 , n/2);
			copy(C21, result, n/2, 0);
			copy(C22, result, n/2, n/2);
		}
		return result;
	}

	public static int [][] add(int [][] A, int [][] B)
	{
		int n = A.length;

		int [][] result = new int[n][n];

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			result[i][j] = A[i][j] + B[i][j];

		return result;
	}

	public static int [][] sub(int [][] A, int [][] B)
	{
		int n = A.length;

		int [][] result = new int[n][n];

		for(int i=0; i<n; i++)
			for(int j=0; j<n; j++)
			result[i][j] = A[i][j] - B[i][j];

		return result;
	}

	public static void divide(int[][] p1, int[][] c1, int iB, int jB)
	{
		for(int i1 = 0, i2=iB; i1<c1.length; i1++, i2++)
			for(int j1 = 0, j2=jB; j1<c1.length; j1++, j2++)
			{
				c1[i1][j1] = p1[i2][j2];
			}
	}

	public static void copy(int[][] c1, int[][] p1, int iB, int jB)
	{
		for(int i1 = 0, i2=iB; i1<c1.length; i1++, i2++)
			for(int j1 = 0, j2=jB; j1<c1.length; j1++, j2++)
			{
				p1[i2][j2] = c1[i1][j1];
			}
	}

    
        public static void print(int [][] array)
	{
		int n = array.length;

		System.out.println();
		for(int i=0; i<n; i++)
		{
			for(int j=0; j<n; j++)
			{
				System.out.print(array[i][j] + "\t");
			}
			System.out.println();
		}
		System.out.println();
	}
    public static void main(String[] args) {
       Random r = new Random(10000);
       Random r1 = new Random(1000);
       int[][] arr = new int[4][4];
       int i,j;
       for(i=0;i<4;i++)
        {
            for(j =0; j<4;j++)
            {
                a[i][j] = 1;
                b[i][j] = 2;
            }
        }
	int a1[][] = { { 1, 2, 3, 4} , { 1, 2, 3, 4} , {1 ,2 ,3 ,4}, {1, 2, 3, 4} };
	int b1[][] = { { 1, 2, 3, 4} , { 1, 2, 3, 4} , {1 ,2 ,3 ,4}, {1, 2, 3, 4} };

	for(i=0;i<4;i++)
        {
            for(j =0; j<4;j++)
            {
                a[i][j] = a1[i][j];
                b[i][j] = b1[i][j];
            }
        }

	arr = strassen(a,b);
       print(arr);
       multiply(a,b);
       
    }

}

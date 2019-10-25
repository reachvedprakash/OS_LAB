import java.util.Scanner;
public class DeadLock_Detection{
	static int allocation[][];
	static int need[][];
	static int maxi[][];
	static boolean isProcessCompleted[];
	static int available[];
	static int m,n;
	static int noOfProcessCompleted=0;
	/* n,m
	 * maxi
	 * allocation
	 * available
	 */
	static void getInput() {
		/* n,m
		 * maxi
		 * allocation
		 * available
		 */
		Scanner scan=new Scanner(System.in);
		System.out.println("Enter number of processes and resources");
		n=scan.nextInt();
		m=scan.nextInt();
		allocation=new int[n][m];
		need=new int[n][m];
		maxi=new int[n][m];
		isProcessCompleted=new boolean[n];
		available=new int[m];
		System.out.println("Enter maximum resources required for each process");
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				maxi[i][j]=scan.nextInt();
		System.out.println("Enter allocated resources required for each process");
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				allocation[i][j]=scan.nextInt();
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				need[i][j]=maxi[i][j]-allocation[i][j];
		System.out.println("Enter the available resources");
		for(int i=0;i<m;i++)
			available[i]=scan.nextInt();
		
		
	}
	static boolean isLess(int x[],int y[]) {
		for(int i=0;i<m;i++)
			if(x[i]>y[i])
				return false;
		return true;
	}
	public static void main(String[] args) {
		getInput();
		boolean isFound=false;
//		System.out.println("Safe processes+Sequence:");
		while(true) {
			for(int i=0;i<n;i++) {
				int x[]=need[i];
				if(!isProcessCompleted[i])
					if(isLess(x,available)) {
						isFound=true;
						System.out.println("Running process "+(i+1));
						isProcessCompleted[i]=true;
						noOfProcessCompleted++;
						for(int j=0;j<m;j++)
							available[j]+=allocation[i][j];
					}
			}
			if(!isFound) {
				//If all the processes are completed
				if(noOfProcessCompleted==n)
					break;
				//If unsafe
				int maxNotCompletedIndex=-1;
				int maxNotCompleted=0;
				for(int i=0;i<n;i++) {
					if(!isProcessCompleted[i]) {
						int sum=0;
						for(int j=0;j<m;j++)
							sum+=allocation[i][j];
						if(sum>maxNotCompleted) {
							maxNotCompleted=sum;
							maxNotCompletedIndex=i;
						}
					}
				}
//				System.out.println();
				System.out.println("Killing process "+(maxNotCompletedIndex+1));
				isProcessCompleted[maxNotCompletedIndex]=true;
				noOfProcessCompleted++;
				for(int j=0;j<m;j++)
					available[j]+=allocation[maxNotCompletedIndex][j];
				
				
				}
			isFound=false;
		}
//		System.out.println();
//		System.out.println("Unsafe processes:");
		for(int i=0;i<n;i++)
			if(!isProcessCompleted[i])
				System.out.print((i+1)+" , ");
	}
}
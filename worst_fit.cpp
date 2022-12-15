#include<iostream>
using namespace std;

void worstFit(int blockSize[], int m, int processSize[],int n)
{
	int allocation[n];

	memset(allocation, -1, sizeof(allocation));

	// pick each process and find suitable blocks
	// according to its size ad assign to it
	for (int i=0; i<n; i++)
	{
	
		int temp = -1;
		for (int j=0; j<m; j++)
		{
			if (blockSize[j] >= processSize[i])
			{
				if (temp== -1)
					temp = j;
				else if (blockSize[temp] < blockSize[j])
					temp = j;
			}
		}

		
		if (temp != -1)
		{
			// allocate block j to p[i] process
			allocation[i] = temp;

			// Reduce available memory in this block.
			blockSize[temp] -= processSize[i];
		}
	}

	cout << "\nProcess No.\tProcess Size\tBlock no.\n";
	for (int i = 0; i < n; i++)
	{
		cout << " " << i+1 << "\t\t" << processSize[i] << "\t\t";
		if (allocation[i] != -1)
			cout << allocation[i] + 1;
		else
			cout << "Not Allocated";
		cout << endl;
	}
}

int main()
{
	int blockSize[] = {100, 500, 200, 300, 600};
	int processSize[] = {257,445,217,159,365};
	int m = sizeof(blockSize)/sizeof(blockSize[0]);
	int n = sizeof(processSize)/sizeof(processSize[0]);

	worstFit(blockSize, m, processSize, n);

	return 0 ;
}

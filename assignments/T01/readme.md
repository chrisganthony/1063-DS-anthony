# Chris Anthony, Take Home Exam
```

```
### Question #1
```cpp

int sumArrays(int A[], int B[], int c[], int size)
{
     int sum = 0;

     for (int i = 0; i < size; i++)
    {
            sum += A[i];
            sum += B[i];
            sum += C[i];
     }

return sum;
}

```
### Question #2
```cpp

	double avg2D(int A[][10], int size)
	{

		double sum = 0.0, avg = 0.0;

		for (int i = 0; i < size; i++)
		{
			for (int j = 0; j < size; j++)
			{
				sum += A[i][j];
			}

			avg = sum / size;
		}

		return avg;
	}

```
### Question #3 (a)
```cpp 
	for (int r = 1; r <= 8; r *= 2)
	{
		for (int c = 0; c < r; c++)
		{
			cout << '*';
		}

		cout << endl;
	}
	
```
### Question #3 (b)
```cpp

	for (int r = 1; r <= 32; r *= 2)
	{
		for (int c = 0; c < r; c++)
		{
			cout << '*';
		}

		cout << endl;
	}

```
### Question #4
```cpp

	Stats aggregateVals(int A[], int size)
	{
		Stats s;

		s.min = A[0];
		s.max = A[0];
		s.avg = 0.0;
		s.sum = 0.0;

		for (int i = 0; i < size; i++)
		{
			if (A[i] < s.min)
			{
				s.min = A[i];
			}

			if (A[i] > s.max)
			{
				s.max = A[i];
			}

			s.sum += A[i];
		}

		s.avg = s.sum / size;
	
		return s;
	}

```
### Question #5
```cpp

	Stats()
	{
		min = 0; 
		max = 0;
		avg = 0.0;
		sum = 0;
	}

```
### Question #6
```cpp
	double calcStdDev(int A[], int size)
	{
		double dif[], sum = 0.0, sum1 = 0.0, avg = 0.0, avg1 = 0.0, result = 0.0;

		for (int i = 0; i < size; i++)
		{
			sum += A[i];
		}
		avg = sum / size;

		for (int i = 0; i < size; i++)
		{
			dif[i] = A[i] - avg;
			dif[i] *= dif[i];
		}
		
		for (int i = 0; i < size; i++)
		{
			sum1 += dif[i];
		}
		avg1 = sum1 / size;
		result = sqrt(avg1);
		
		return result;
	}
	
```
### Question #7
```cpp

	void initIntArray(int *&A, int size)
	{
		A = new int[size];

		for (int i - 0; i < size; i++)
		{
			A[i] = 0;
		}
	}

```

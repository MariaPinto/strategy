
template <class T>
void bubble_sort<T>::sort(T *i, size_t n)
{
	bool s=true;
	
	for (int k=0; k<n-1; k++ )
	{
		for(int j=0;j<n-k-1;j++)
		{
			if(*(i+j)>*(i+j+1))
			{
				swapy((i+j),(i+j+1));
			}
		}
	}
}

template <class T>
void bubble_sort<T>::swapy(T *xp, T *yp)
{
	T temp= *xp;
	*xp=*yp;
	*yp=temp;
}


template <class T>
void insert_sort<T>::sort(T *i, size_t n)
{
	int j;
	T  key;
	for(int k=0; k<n; k++)
	{
		
		j=k;
		
		while(j>0 && *(i+j)<*(i+j-1))
		{
			key=*(i+j);
			*(i+j)=*(i+j-1);
			*(i+j-1)=key;
			
			j--;
		}
	}
}



template <class T>
void shell_sort<T>::sort(T *i, size_t n)
{
	T temp;
	for(int gap=n/2; gap>0; gap/=2)
	{
		for(int h=gap; h<n; h++ )
		{
			for(int k=h-gap; k>=0; k--)
			{
				if(*(i+k+gap)>*(i+k))
					break;
				else
				{
					temp=*(i+k);
					*(i+k)=*(i+k+gap);
					*(i+k+gap)=temp;
				}
			}
		}
	}
}


template <class T>
void merge_sort<T>::merge(T *a,int low, int high, int mid)
{
	int i=low;
	int k=0;
	int j=mid+1;
	T temp[(high-low)+1];
	
	while(i<=mid && j<=high)
	{
		if(*(a+i)<*(a+j))
		{
			temp[k]=*(a+i);
			k++;
			i++;
		}
		else
		{
			temp[k]=*(a+j);
			k++;
			j++;
		}
		
	}
	while(i<=mid)
	{
		temp[k]=*(a+i);
		k++;
		i++;
	}
	
	while(j<=high)
	{
		temp[k]=*(a+j);
		k++;
		j++;
	}
	
	for(i=low;i<=high; i++)
	{
		*(a+i)=temp[i-low];
	}
}

template <class T>
void merge_sort<T>:: merging(T *a, int low, int high)
{
	int mid;
	if(low<high)
	{
		mid=(low+high)/2;
		merging(a,low,mid);
		merging(a,mid+1,high);
		
		merge(a,low,high,mid);
	}
}

template <class T>
void merge_sort<T>:: sort(T *i, size_t n)
{
	merging(i,0,n-1);
}


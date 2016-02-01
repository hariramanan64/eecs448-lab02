/**
*	@author hari ramanan and John gibbons
*	@date 2/1/2016
*	@file LinkedList.hpp
*	@brief Implementation file for templated LinkedList class
*/

template <typename T>
LinkedList<T>::LinkedList() : m_front(nullptr), m_size(0)
{

}

template <typename T>
LinkedList<T>::~LinkedList() 
{
	while(!isEmpty())
	{
		removeFront();
	}
}

template <typename T>
bool LinkedList<T>::isEmpty() const
{
	return(m_size == 0);
}

template <typename T>
int LinkedList<T>::size() const
{
	/** TODO 
		done
	*/
	return m_size;
}

template <typename T>
bool LinkedList<T>::search(T value) const
{
	Node<T>* currPtr = m_front;
	bool isFound = false;

	/** TODO 
		done
	*/

	while(currPtr)
	{
		if(value == (currPtr -> getValue()))
		{
			return true;
		}
		currPtr = (currPtr -> getNext());
	}
	return false;
	
}

template <typename T>
std::vector<T> LinkedList<T>::toVector() const
{
	std::vector<T> vec;
	Node<T>* temp = m_front;

	while( temp != nullptr )
	{
		vec.push_back(temp->getValue());
		temp = temp->getNext();
	}

	return(vec);	
	
}

template <typename T>
void LinkedList<T>::addBack(T value)
{
	Node<T>* temp = nullptr;

	if(isEmpty())
	{
		m_front = new Node<T>(value);	
	}
	else
	{
		temp = m_front;
		while(temp->getNext() != nullptr)
		{
			temp = temp->getNext();
		}

		temp->setNext( new Node<T>(value) );		
	}

	m_size++;
}

template <typename T>
void LinkedList<T>::addFront(T value)
{
	Node<T>* temp = m_front;
	m_front = new Node<T>(value);
	m_front->setNext( temp );
	m_size++;
}

template <typename T>
bool LinkedList<T>::removeBack()
{
	/** TODO 
		Fix this method
	*/

	if(isEmpty())
	{
		return false; 
	}
	else if(m_size == 1)
	{
		Node<T>* temp = m_front; 
		delete temp; 
		m_front = nullptr;
		m_size--;
	}
	else 
	{
		Node<T>* temp1 = backHelper1();	
		Node<T>* temp2 = backHelper2();	
		delete temp1;
		temp2 -> setNext(nullptr);
		m_size--;	
	}
	return true;
}	

template <typename T>
bool LinkedList<T>::removeFront()
{
	Node<T>* temp = nullptr;
	bool isRemoved = false;

	if(!isEmpty())
	{
		temp = m_front;
		m_front = temp->getNext();
		delete temp;
		m_size--;
		isRemoved = true;
	}

	return(isRemoved);
}

template <typename T>
Node<T>* LinkedList<T>::backHelper1()
{
	Node<T>* endPtr; 
	Node<T>* temp;
	endPtr = m_front;
	if(m_front != nullptr)
	{
		temp = m_front -> getNext();
	} 
	while(temp)
	{
		endPtr = temp; 
		temp = temp -> getNext();
	}
	return endPtr; 
}

template <typename T>
Node<T>* LinkedList<T>::backHelper2()
{
	Node<T>* endPtr; 
	Node<T>* temp; 
	temp = m_front;
	if(m_front != nullptr)
	{
		endPtr = temp -> getNext();
	}
	while((endPtr -> getNext()) != nullptr)
	{
		temp = endPtr; 
		endPtr = endPtr -> getNext();
	}
	return temp; 		
}

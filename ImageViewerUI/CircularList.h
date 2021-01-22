/*
Project: Image Viewer App using Circular Doubly Linked List
Author: Abdul Mannan
*/
using namespace System;

namespace ImageViewerUI {

#pragma region Struct
#pragma unmanaged
template <typename T>
	struct ListNode
	{
	public:
		int key = -1;
		T data;

		ListNode<T>* next = nullptr;
		ListNode<T>* prev = nullptr;
	};
#pragma endregion

#pragma region Class
#pragma managed
template <typename T>
	ref class CircularList
	{
	private:
#pragma region PrivateFunctions
		Void SetIndices();
#pragma endregion

	public:
#pragma region Constructor/Destructor
		CircularList();
		~CircularList();
#pragma endregion

#pragma region Variables
		ListNode<T>* head;
		ListNode<T>* tail;
#pragma endregion

#pragma region Properties
		property Int32 Length
		{
			Int32 get()
			{
				Int32 length = 0;
				ListNode<T>* current = head;

				if (current == nullptr)
					return 0;

				//navigate till the end of the list
				do
				{
					length++;
					current = current->next;
				} while (current != head);

				return length;
			}
		}
#pragma endregion

#pragma region Functions
		Void Add(T data);
		Boolean Edit(int index, T value);
		Boolean Insert(int index, T value);
		Boolean Delete(int index);
		int IndexOf(T value);
		Void Clear();
		ListNode<T>* ItemAt(int index);
#pragma endregion

	};
#pragma endregion
	
#pragma region Definitions
	template<typename T>
	CircularList<T>::CircularList()
	{
		head = nullptr;
		tail = nullptr;
	}

	template<typename T>
	CircularList<T>::~CircularList()
	{
		Clear();
	}

	template<typename T>
	Void CircularList<T>::SetIndices()
	{
		ListNode<T>* current = head;
		for (int i = 0; i < Length; ++i) {
			current->key = i;
			current = current->next;
		}
	}

	template<typename T>
	Void CircularList<T>::Add(T data)
	{
		//allocate memory
		ListNode<T>* Link = new ListNode<T>;
		Link->key = Length;
		Link->data = data;

		if (Length == 0) {
			Link->prev = Link;
			Link->next = Link;
			head = Link;
		}
		else {
			Link->prev = tail;
			tail->next = Link;
			Link->next = head;
			head->prev = Link;
		}
		tail = Link;
	}

	template<typename T>
	Boolean CircularList<T>::Edit(int index, T value)
	{
		if (index < 0 || index > Length - 1)
		{
			return false;
		}
		else
		{
			ListNode<T>* edit = head;
			while (edit->key != index)
			{
				edit = edit->next;
			}
			edit->data = value;

			return true;
		}
	}

	template<typename T>
	Boolean CircularList<T>::Insert(int index, T value)
	{
		if (index < 0 || index > Length - 1)
		{
			return false;
		}
		else
		{
			//allocate memory
			ListNode<T>* link = new ListNode<T>;
			link->data = value;

			ListNode<T>* current = head;
			ListNode<T>* prev;
			while (current->key != index)
			{
				current = current->next;
			}
			prev = current->prev;

			if (index == 0)
			{
				link->next = head;
				head->prev = link;
				head = link;
				head->prev = tail;
				tail->next = head;
			}
			else
			{
				prev->next = link;
				link->prev = prev;
				current->prev = link;
				link->next = current;
			}

			SetIndices();

			return true;
		}
	}

	template<typename T>
	Boolean CircularList<T>::Delete(int index)
	{
		if (index < 0 || index > Length - 1)
		{
			return false;
		}
		else
		{
			ListNode<T>* current = head;
			ListNode<T>* prev;
			ListNode<T>* next;
			while (current->key != index)
			{
				current = current->next;
			}
			prev = current->prev;
			next = current->next;

			//there is only one node
			if (prev == current)
			{
				head = nullptr;
				tail = nullptr;
			}
			else
			{
				//first node
				if (prev == tail)
				{
					head = next;
					head->prev = tail;
					tail->next = head;
				}
				//last node
				else if (next == head)
				{
					tail = prev;
					head->prev = tail;
					tail->next = head;
				}
				else
				{
					next->prev = prev;
					prev->next = next;
				}
			}

			//free memory
			delete current;

			SetIndices();

			return true;
		}
	}

	template<typename T>
	int CircularList<T>::IndexOf(T value)
	{
		int ind = -1;
		ListNode<T>* current = head;

		for (int i = 0; i < Length; ++i)
		{
			if (current->data == value)
			{
				ind = current->key;
				break;
			}
			current = current->next;
		}

		return ind;
	}

	template<typename T>
	Void CircularList<T>::Clear()
	{
		//clear list
		for (int i = 0; i < Length; ++i)
		{
			Delete(i);
		}
		head = nullptr;
		tail = nullptr;
	}

	template<typename T>
	inline ListNode<T>* CircularList<T>::ItemAt(int index)
	{
		ListNode<T>* current = head;

		for (int i = 0; i < Length; ++i)
		{
			if (current->key == index)
			{
				return current;
			}
			current = current->next;
		}
		return nullptr;
	}
#pragma endregion

}
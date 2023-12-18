#pragma once
#include "iostream"
#include <vector>
using namespace std;
template<typename T>
class TSinglList {
	struct TNode {
		T value;
		TNode* pNext;
	};
	TNode* pFirst;
	size_t sz;
public:
	TSinglList(): pFirst(nullptr), sz(0){}
	TSinglList(const vector <T>& v) {
		for (int i = v.size(); i > 0; i--)
			PushFront(v[i - 1]);
	}

	TSinglList(const TSinglList& list) : pFirst(nullptr), sz(list.sz) {
		if (list.pFirst == nullptr)
			return;
		TNode* pNew = pFirst = new TNode{ *list.pFirst };
		for (; pNew->pNext != nullptr; pNew = pNew->pNext)
			pNew->pNext = new TNode{ *pNew->pNext };
	}
	TSinglList(TSinglList&& list) noexcept {
		pFirst = nullptr;
		swap(*this, list);
	}

	TSinglList& operator=(const TSinglList& list) {
		if (this != &list) {
			TSinglList tmp(list);
			swap(*this, tmp);
		}
		return *this;
	}

	TSinglList& operator=(const TSinglList&& list) noexcept {
		swap(*this, list);
		return *this;
	}

	~TSinglList() {
		TNode* p;
		while (pFirst != nullptr) {
			p = pFirst;
			pFirst = pFirst->pNext;
			delete p;
		}
	}

	size_t size() const noexcept {
		return sz;
	}
	void PushFront(const T& val) {
		TNode* node = new TNode{ val,pFirst };
		pFirst = node;
		sz++;
	}

	void PopFront() noexcept {
		TNode* p = pFirst;
		pFirst = pFirst->pNext;
		delete p;
		sz--;
	}
};

//
//void split(L *&l,L *&l1,L *&l2){
//	l1=l;
//	r1=l;
//	r2=(L*malloc(sizeof(L));
//	l2->next=nullptr;
//	while(p!=nullptr){
//		q=p->next->next;
//		l1->next=p;
//		r1=p;
//		p=p->next;
//		p->next=l2->next;
//		l->next=p;
//		p=q;
//	}
//	r1->next=nullptr;
//}
//
//void dele(L *&l){
//
//	L *&p,*&prep,*&max,*&premax;
//	q=p;
//	p=p->next;
//	max=p;
//	premax=q;
//	while(p!=nullptr){
//		if(max->data<p->datd){
//			max=p;
//			premaxn=pre;
//		}
//		pre=pre->enxt;
//		p=p->next;
//	}
//	prep->next=max->next;
//	free(max);
//}
//
//
//void Insertbeforex(LinkNode *&L,ElemType x) {
//	LinkNode *p=L->next,*pre=L;
//	LinkNode *maxp=p,*maxpre=L,*s;
//	while (p!=nullptr)  {
//		if (maxp->data<p->data)   {
//			maxp=p;    maxpre=pre;
//		}   pre=p; p=p->next;
//	}
//	s=(LinkNode *)malloc(sizeof(LinkNode));
//	s->data=x;
//	s->next=maxpre->next;
//	maxpre->next=s;
//}
//void DelOdd(LinkNode *L){
//	LinkNode *p=L->next,*q=L,*t=nullptr;
//	while(p!=nullptr){/*两种情况*/
//		if(p->next==nullptr){
//			q->next=nullptr;
//			free(p);return ;
//		}
//		t=p;
//		q->next=p->next;
//		q=p->next;
//		p=q->next;
//		free(t);
//	}
//}
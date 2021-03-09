
/*
pcurr->pnext->
qcurr->qnext->

=> pcurr->qcurr->pnext->qnext->
 */

void merge(node *p, node *&q) {
	node *p_curr = p, *q_curr = q, *p_next, q_next;

	while (p_curr and q_curr) {

		p_next = p_curr->next;
		q_next = q_curr->next;

		q_curr->next = p_next;
		p_curr->next = q_curr;

		p_curr = p_next;
		q_curr = q_next;
	}
	q = q_curr;
}
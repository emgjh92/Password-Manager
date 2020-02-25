#pragma warning(disable:4996)
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h> 
#include <math.h>


//---------------------------------------------------------------
//-----------------------------------------------------------------
void change(char *ch, int a, char b, int n) {

	ch[a] ^= b;
	ch[a] &= 0x0f;
	ch[a] |= 0x30;
	ch[a] = (((ch[a] - 48) % 10 + 48 + n % 10) - 48) % 10 + 48;

}
void change2(char *ch, int a, int i) {
	if (i == 0) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x08);
		else (ch[a] = (ch[a] >>= 1) & 0x07);
	}
	if (i == 1) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x08);
		else (ch[a] = (ch[a] >>= 1));
	}
	if (i == 2) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x01);
		else (ch[a] = (ch[a] >>= 1) & 0x07);
	}
	if (i == 3) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x01);
		else (ch[a] = (ch[a] >>= 1));
	}
	if (i == 4) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x04);
		else (ch[a] = (ch[a] >>= 1) & 0x07);
	}
	if (i == 5) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) & 0x07);
		else (ch[a] = (ch[a] >>= 1) & 0x0b);
	}
	if (i == 6) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x04);
		else (ch[a] = (ch[a] >>= 1));
	}
	if (i == 7) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x02);
		else (ch[a] = (ch[a] >>= 1) & 0x07);
	}
	if (i == 8) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x02);
		else (ch[a] = (ch[a] >>= 1));
	}
	if (i == 9) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) & 0x0d);
		else (ch[a] = (ch[a] >>= 1) & 0x0e);
	}
	ch[a] &= 0x0f;
	ch[a] |= 0x30;
	ch[a] = (((ch[a] - 48) % 10 + 48 + i % 10) - 48) % 10 + 48;

}



void intcase2(char *ch, int nike) {
	int **arr = (int**)malloc((sizeof(int*) * 1000));
	for (int i = 0; i < strlen(ch); i++) {
		arr[i] = (int*)malloc((sizeof(int) * 1000));
	}
	int cnt = 0, m, n;
	int chcnt = 0;
	int idx;
	char tmpc, chb;
	nike += 3;
	n = sqrt(strlen(ch)) + 1;
	m = sqrt(strlen(ch)) + 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i + 1; j++) {
			nike++;
			if (j < n) {
				arr[j][i - j] = ++cnt;

			}
		}
	}

	for (int i = 1; i < n; i++) {
		nike++;
		for (int j = 0; j < n - i; j++) {
			if (j < m)
				arr[i + j][m - 1 - j] = ++cnt;

		}
	}
	nike++;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] - 1 < strlen(ch)) {
				nike += 2;
				if (chcnt == 0) {
					change2(ch, arr[i][j] - 1, (nike) % 10);
					idx = arr[i][j] - 1;
					chb = ch[arr[i][j] - 1];
					chcnt++;
				}
				else {
					//--------------------------------------
					nike++;
					change2(ch, arr[i][j] - 1, (nike) % 10);
					change(ch, arr[i][j] - 1, chb, nike);
					//---------------------------------
					tmpc = ch[arr[i][j] - 1];
					ch[arr[i][j] - 1] = chb;
					chb = tmpc;
				}
				nike++;
			}
		}
	}
	ch[idx] = chb;
}

void intcase3(char *ch, int nike) {

	int cnt = 0, cnt1, cnt2, n, m, i = 0, j = -1, aa = -1, m1, n1, idx;
	int chcnt = 0;
	char tmpc, chb;
	int **a = (int**)malloc((sizeof(int*) * 1000));
	for (int i = 0; i < strlen(ch); i++) {
		a[i] = (int*)malloc((sizeof(int) * 1000));
	}
	n = sqrt(strlen(ch)) + 1;
	m = sqrt(strlen(ch)) + 2;
	m1 = m;
	n1 = n;
	cnt1 = 0, cnt2 = 0;
	while (1) {
		aa *= -1;
		while (cnt1 < m) {
			j += aa;
			a[i][j] = ++cnt;
			nike++;
			cnt1++;
		}
		cnt1 = 0;

		cnt--;
		while (cnt2 < n) {
			nike += 3;
			a[i][j] = ++cnt;
			i += aa;
			cnt2++;

		}
		i -= aa;
		cnt2 = 0;
		n--;
		m--;
		if (cnt == n1 * m1)
			break;
	}
	for (int i = 0; i < n1; i++) {
		nike++;
		for (int j = 0; j < m1; j++) {
			if (a[i][j] - 1 < strlen(ch)) {
				change2(ch, a[i][j] - 1, (nike) % 10);

				if (chcnt == 0) {
					idx = a[i][j] - 1;
					chb = ch[a[i][j] - 1];
					chcnt++;
				}
				else {

					//-----------------------------------------
					change2(ch, a[i][j] - 1, (nike) % 10);
					change(ch, a[i][j] - 1, chb, nike);
					//------------------------------------------
					tmpc = ch[a[i][j] - 1];
					ch[a[i][j] - 1] = chb;
					chb = tmpc;
				}
			}
		}
	}
	ch[idx] = chb;

}

//-------------------------------------------------------------------------
//-------------------------------------------------------------------------

void chchange(char *ch, int a, char b, int n) {

	ch[a] ^= b;
	ch[a] = ((ch[a] % 94 + 33) + n) % 94 + 33;
}
void chchange2(char *ch, int a, int i) {
	for (int j = 0; j <= i; j++) {
		if (ch[a] & (0x01)) (ch[a] = (ch[a] >> 1) | 0x40);
		else (ch[a] >>= 1);
	}
	ch[a] = ((ch[a] % 94 + 33) + i) % 94 + 33;

}
//-----------------------------------------------------------------


void charcase2(char *ch, int nike) {
	int **arr = (int**)malloc((sizeof(int*) * 1000));
	for (int i = 0; i < strlen(ch); i++) {
		arr[i] = (int*)malloc((sizeof(int) * 1000));

	}
	int cnt = 0, m, n;
	int chcnt = 0;
	int idx;
	char tmpc, chb;
	nike += 3;
	n = sqrt(strlen(ch)) + 1;
	m = sqrt(strlen(ch)) + 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i + 1; j++) {
			nike++;
			if (j < n) {
				arr[j][i - j] = ++cnt;

			}
		}
	}

	for (int i = 1; i < n; i++) {
		nike++;
		for (int j = 0; j < n - i; j++) {
			if (j < m)
				arr[i + j][m - 1 - j] = ++cnt;

		}
	}

	nike++;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] - 1 < strlen(ch)) {
				nike += 2;
				if (chcnt == 0) {
					chchange2(ch, arr[i][j] - 1, (nike) % 10);
					idx = arr[i][j] - 1;
					chb = ch[arr[i][j] - 1];
					chcnt++;
				}
				else {
					//--------------------------------------
					nike++;
					chchange2(ch, arr[i][j] - 1, (nike) % 10);
					chchange(ch, arr[i][j] - 1, chb, nike);
					//---------------------------------
					tmpc = ch[arr[i][j] - 1];
					ch[arr[i][j] - 1] = chb;
					chb = tmpc;
				}
				nike++;
			}
		}
	}
	ch[idx] = chb;
}

void charcase3(char *ch, int nike) {
	int **a = (int**)malloc((sizeof(int*) * 1000));
	for (int i = 0; i < strlen(ch); i++) {
		a[i] = (int*)malloc((sizeof(int) * 1000));
	}
	int cnt = 0, cnt1, cnt2, n, m, i = 0, j = -1, aa = -1, m1, n1, idx;
	int chcnt = 0;
	char tmpc, chb;
	n = sqrt(strlen(ch)) + 1;
	m = sqrt(strlen(ch)) + 2;
	m1 = m;
	n1 = n;
	cnt1 = 0, cnt2 = 0;
	while (1) {
		aa *= -1;
		while (cnt1 < m) {
			j += aa;
			a[i][j] = ++cnt;
			nike++;
			cnt1++;
		}
		cnt1 = 0;

		cnt--;
		while (cnt2 < n) {
			nike += 3;
			a[i][j] = ++cnt;
			i += aa;
			cnt2++;

		}
		i -= aa;
		cnt2 = 0;
		n--;
		m--;
		if (cnt == n1 * m1)
			break;
	}
	for (int i = 0; i < n1; i++) {
		nike++;
		for (int j = 0; j < m1; j++) {
			if (a[i][j] - 1 < strlen(ch)) {
				chchange2(ch, a[i][j] - 1, (nike) % 10);

				if (chcnt == 0) {
					idx = a[i][j] - 1;
					chb = ch[a[i][j] - 1];
					chcnt++;
				}
				else {

					//-----------------------------------------
					chchange2(ch, a[i][j] - 1, (nike) % 10);
					chchange(ch, a[i][j] - 1, chb, nike);
					//------------------------------------------
					tmpc = ch[a[i][j] - 1];
					ch[a[i][j] - 1] = chb;
					chb = tmpc;
				}
			}
		}
	}
	ch[idx] = chb;

}



//---------------------------------------------------------------------------
//---------------------------------------------------------------------

void case2(char *ch) {
	int **arr = (int**)malloc((sizeof(int*) * 1000));
	for (int i = 0; i < strlen(ch); i++) {
		arr[i] = (int*)malloc((sizeof(int) * 1000));
	}
	int cnt = 0, m, n;
	int chcnt = 0;
	int idx;
	char tmpc, chb;
	n = sqrt(strlen(ch)) + 1;
	m = sqrt(strlen(ch)) + 2;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < i + 1; j++) {
			if (j < n) {
				arr[j][i - j] = ++cnt;

			}
		}
	}

	for (int i = 1; i < n; i++) {
		for (int j = 0; j < n - i; j++) {
			if (j < m)
				arr[i + j][m - 1 - j] = ++cnt;

		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] - 1 < strlen(ch)) {
				if (chcnt == 0) {
					idx = arr[i][j] - 1;
					chb = ch[arr[i][j] - 1];
					chcnt++;
				}
				else {

					tmpc = ch[arr[i][j] - 1];
					ch[arr[i][j] - 1] = chb;
					chb = tmpc;
				}
			}
		}
	}
	ch[idx] = chb;
}

void case3(char *ch) {
	int cnt = 0;
	int cnt1, cnt2;
	int **a = (int**)malloc((sizeof(int*) * 1000));
	for (int i = 0; i < strlen(ch); i++) {
		a[i] = (int*)malloc((sizeof(int) * 1000));
	}
	int n, m;
	int i = 0, j = -1, aa = -1;
	int m1, n1, idx;
	int chcnt = 0;
	char tmpc, chb;

	m = sqrt(strlen(ch)) + 1;
	n = sqrt(strlen(ch));
	m1 = m;
	n1 = n;
	cnt1 = 0, cnt2 = 0;

	while (1) {

		aa *= -1;
		while (cnt1 < m) {
			j += aa;
			a[i][j] = ++cnt;
			cnt1++;
		}
		cnt1 = 0;

		cnt--;
		while (cnt2 < n) {
			a[i][j] = ++cnt;
			i += aa;
			cnt2++;

		}
		i -= aa;
		cnt2 = 0;
		n--;
		m--;
		if (cnt == n1 * m1)
			break;
	}

	for (int i = 0; i < n1; i++) {
		for (int j = 0; j < m1; j++) {
			if (a[i][j] - 1 < strlen(ch)) {

				if (chcnt == 0) {
					idx = a[i][j] - 1;
					chb = ch[a[i][j] - 1];
					chcnt++;
				}
				else {

					tmpc = ch[a[i][j] - 1];
					ch[a[i][j] - 1] = chb;
					chb = tmpc;
				}
			}
		}
	}
	ch[idx] = chb;

}

void composition(char *ch) {

	int i, j, len;
	char tmp;

	len = strlen(ch);

	i = (len / 2) + 1;

	while (i > -1) {

		if (ch[i] >= 'a'&&ch[i] <= 'v') {
			if (ch[len - i - 1] >= '0'&&ch[len - i - 1] <= '9') {
				tmp = ch[i];
				ch[i] = ch[len - i - 1];
				ch[len - i - 1] = tmp;
			}
		}
		i--;
	}

	for (i = 0; i < len; i++) {
		for (j = len - 1; j >= 0; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}
	for (i = 0; i < len; i++) {
		for (j = len - 1; j >= 0; j--) {
			if (ch[i] >= 'a'&&ch[i] <= 'h'&&ch[j] >= '0'&&ch[j] <= '9') {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	i = 0;

	while (i < len) {
		if (ch[i] == '?' || ch[i] == '>') {
			tmp = ch[i];
			ch[i] = ch[len - i - 1];
			ch[len - i - 1] = tmp;
		}
		i++;
	}
	for (i = 0; i < len - 1; i++) {
		for (j = len - 2; j >= 0; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = len / 2; i < len; i++) {
		for (j = 0; j <= len / 2; j++) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	i = 0;

	while (i < len) {
		if (ch[i] >= '4'&&ch[i] <= '8') {
			tmp = ch[i];
			ch[i] = ch[len - i - 1];
			ch[len - i - 1] = tmp;
		}
		i++;
	}

	for (i = 1; i < len; i++) {
		for (j = len - 1; j >= 1; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = 0; i < len / 2; i++) {
		for (j = (len - 1) / 2; j >= 0; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}


	for (i = 0; i < len; i++) {
		for (j = len - 1; j >= 0; j--) {
			if (i % 2 == 0) {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	for (i = 0; i < len / 2; i++) {
		for (j = (len - 1) / 2; j >= 0; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = 0; i < len; i++) {
		for (j = len - 1; j >= 0; j--) {
			if (i % 2 != 0) {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	for (i = 0; i < len; i++) {
		for (j = len - 1; j >= len / 2; j--) {
			if (ch[i] > 'c'&&ch[i] < 'u') {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	for (i = 0; i < len / 2; i++) {
		for (j = (len - 1) / 2; j >= 0; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = 0; i < len; i++) {
		for (j = i; j < len; j++) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = 0; i < len - 1; i++) {
		for (j = len - 2; j >= 0; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = 0; i <= len / 2; i++) {
		for (j = len / 2; j < len; j++) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}
	for (i = 0; i < len; i++) {
		for (j = len - 1; j >= 0; j--) {
			if (j % 2 == 0) {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	for (i = 0; i < len / 2; i++) {
		tmp = ch[i];
		ch[i] = ch[len - i - 1];
		ch[len - i - 1] = tmp;
	}

	for (i = 0; i < len; i++) {
		for (j = len - 1; j > 0; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = 0; i < len / 2; i++) {
		for (j = len - 1; j >= 0; j--) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j <= len / 2; j++) {
			if (ch[j] == '_') {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	i = len - 1;

	while (i > -1) {
		if (ch[i] >= 'a'&&ch[i] <= 'z') {
			if (ch[len - i - 1] >= '1' || ch[len - i - 1] <= '6') {
				if (ch[i] != 'c'&&ch[i] != 'd') {
					tmp = ch[i];
					ch[i] = ch[len - i - 1];
					ch[len - i - 1] = tmp;
				}
			}
		}
		i--;
	}

	for (i = 0; i < len - 1; i++) {
		for (j = 0; j <= len / 2; j++) {
			tmp = ch[i];
			ch[i] = ch[j];
			ch[j] = tmp;
		}
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j <= len / 2; j++) {
			if (i % 2 == 0) {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			if (j % 2 == 0) {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}
	switch (ch[3]) {

	case '1': {tmp = ch[3];
		ch[3] = ch[len - 1 - 3];
		ch[len - 1 - 3] = tmp;
	}
	case 'b': {tmp = ch[3];
		ch[3] = ch[len - 1 - 3];
		ch[len - 1 - 3] = tmp;
	}
	case '!': {tmp = ch[3];
		ch[3] = ch[len - 1 - 3];
		ch[len - 1 - 3] = tmp;
	}
	case '>': {tmp = ch[3];
		ch[3] = ch[len - 1 - 3];
		ch[len - 1 - 3] = tmp;
	}
	case 'v': {tmp = ch[3];
		ch[3] = ch[len - 1 - 3];
		ch[len - 1 - 3] = tmp;
	}
	case 'o': {tmp = ch[3];
		ch[3] = ch[len - 1 - 3];
		ch[len - 1 - 3] = tmp;
	}
	case '6': {tmp = ch[3];
		ch[3] = ch[len - 1 - 3];
		ch[len - 1 - 3] = tmp;
	}
	case '0': {tmp = ch[3];
		ch[3] = ch[len - 1 - 3];
		ch[len - 1 - 3] = tmp;
	}
	}

	for (i = 0; i < len; i++) {
		for (j = len - 1; j >= 0; j--) {
			if (j % 2 != 0 && i % 2 != 0) {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			if (ch[i] > '0'&&ch[i] < '5') {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			if (ch[i] == '!') {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	i = len - 1;

	while (i > -1) {
		if (ch[i] >= 'A'&&ch[i] <= 'Z') {
			if (ch[len - i - 1] >= '3' || ch[len - i - 1] <= '9') {
				tmp = ch[i];
				ch[i] = ch[len - i - 1];
				ch[len - i - 1] = tmp;
			}
		}
		i--;
	}

	for (i = 0; i < len; i++) {
		for (j = 0; j < len; j++) {
			if (j % 2 != 0 || (ch[i] >= 'a'&&ch[i] <= 'z')) {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

	for (i = 0; i < len; i++) {
		for (j = len - 1; j >= 0; j--) {
			if (ch[i] >= 'A'&&ch[i] <= 'G') {
				tmp = ch[i];
				ch[i] = ch[j];
				ch[j] = tmp;
			}
		}
	}

}




char* itoa(int val, char * buf, int radix) {

	char* p = buf;

	while (val) {

		if (radix <= 10)
			*p++ = (val % radix) + '0';

		else {
			int t = val % radix;
			if (t <= 9)
				*p++ = t + '0';
			else
				*p++ = t - 10 + 'a';
		}

		val /= radix;
	}

	*p = '\0';
	return buf;
}

char *int2char(int *p, int cnt) {
	char *b;
	int i = 0;
	b = (char *)malloc(sizeof(char) * 10000);
	char c[10000] = { '\0' };
	for (i = 0; i < cnt; i++) {
		itoa(p[i], &b[i], 10);
		strcat(c, &b[i]);
	}

	return &c[0];
}

char *func(char *pass, char *cpass) {
	int *enc;
	int add;
	int i, j, k = 0;

	enc = (int*)malloc(sizeof(int)*(int)(strlen(pass) + strlen(cpass) - 1) + 1);
	for (j = 0; j < (int)strlen(pass) + (int)strlen(cpass) - 1; j++) {
		enc[j] = 0;
	}
	for (i = 1; i < strlen(cpass); i++) {
		add = 0;
		for (j = 0; j < i; j++) {
			add += pass[i - 1 - j] * cpass[j];
		}
		enc[i - 1] = add;
	}
	for (i = (int)strlen(cpass); i <= (int)strlen(pass) - 1; i++) {
		add = 0;
		for (j = 0; j < strlen(cpass); j++) {
			add += pass[i - 1 - j] * cpass[j];
		}
		enc[i - 1] = add;
	}
	for (i = (int)strlen(cpass); i > 0; i--) {
		k++;
		add = 0;
		for (j = 0; j < i; j++) {
			add += pass[strlen(pass) - 1 - j] * cpass[j + k - 1];
		}
		enc[strlen(pass) - 2 + k] = add;
	}

	return int2char(enc, strlen(pass) + strlen(cpass) - 1);

}
char* encrypt_isdigit(char *str) {
	int x = 0;

	for (x = 0; x<strlen(str); x++) {

		if (isdigit(str[x]))
		{

			str[x] = (str[x] - '0' + 3) % 10 + '0';
		}

	}
	return str;
}
//==============================================================================
char* encrypt_rot10(char *str) {

	int i = 0;
	int c = 0;

	for (i = 0; i < strlen(str); i++) {
		if (str[c] >= 'a' && str[c] <= 'm') str[c] += 10;
		else if (str[c] >= 'A' && str[c] <= 'M') str[c] += 10;
		else if (str[c] >= 'n' && str[c] <= 'z') str[c] -= 10;
		else if (str[c] >= 'N' && str[c] <= 'Z') str[c] -= 10;
		c++;
	}
	return str;

}
//
//==============================================================================

//=======================Masking===================================================
void data_masking(char *arr) {

	char rarr[100];
	int i = 0;

	while ((arr[i] = getch()) != '\r') {
		if (arr[i] == 8) {
			if (i > 0) {
				printf("\b");
				printf(" ", stdout);
				printf("\b");

				arr[i - 1] = '\0';
				i--;
			}

		}
		else {
			printf("*");
			rarr[i] = arr[i];
			i++;
		}
	}
	printf("\n");
	rarr[i] = '\0';
	strcpy(arr, rarr);
}

//=======================================================================================


//=======================================================================================
char* encrypt_basic(char *str) {
	int x = 0;
	char *tem;
	char *add;
	tem = (char*)malloc(sizeof(char) * 100000);
	add = (char*)malloc(sizeof(char) * 100000);
	strcpy(tem, str);
	strcpy(add, str);
	encrypt_isdigit(str);
	encrypt_rot10(str);

	for (x = 0; x<strlen(str); x++) {
		str[x] = ((str[x] - 33) + 10) % 95 + 33;
	}
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 3; i++) {
			if (strlen(add) % 2 == 0) {
				charcase2(add, strlen(add));
				charcase3(add, strlen(add));
			}
			else {
				charcase3(add, strlen(add));
				charcase2(add, strlen(add));
			}
		}
		strcat(tem, add);
	}
	for (int j = 0; j < 2; j++) {
		for (int i = 0; i < 3; i++) {
			if (strlen(add) % 2 == 0) {
				charcase3(add, strlen(add));
				charcase2(add, strlen(add));
			}
			else {
				charcase2(add, strlen(add));
				charcase3(add, strlen(add));
			}
		}
		strcat(str, add);
	}
	composition(str);
	case2(str);
	str = func(str, tem);
	strcpy(add, str);
	for (int i = 0; i < 3; i++) {
		if (strlen(str) % 2 == 0) {
			intcase2(add, strlen(str) % 10);
			intcase3(add, strlen(str) % 10);

		}
		else {
			intcase3(add, strlen(str) % 10);
			intcase2(add, strlen(str) % 10);
		}
		strcat(str, add);
	}
	case3(str);
	composition(str);

	return str;

}
//=======================================================================================
void printletter() {
	printf("Password should be...\n");
	printf("         1. at least 8 characters long\n");
	printf("         2. contains at least one letter and digit\n");
	printf("         3. contains at least one of these four characters:<,>,_,?,!\n\n");
}
//=======================================================================================
int checkpassword(char *cpass) {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int i = 0;
	for (i = 0; i < strlen(cpass); i++) {

		if (*(cpass + i) >= 'a' && *(cpass + i) <= 'z')
			cnt1++;
		if (*(cpass + i) >= 'A' && *(cpass + i) <= 'Z')
			cnt1++;
		if (*(cpass + i) >= '0' && *(cpass + i) <= '9')
			cnt2++;
		if (*(cpass + i) == '>' || *(cpass + i) == '<' || *(cpass + i) == '_' || *(cpass + i) == '?' || *(cpass + i) == '!')
			cnt3++;
	}
	if (strlen(cpass) > 28)
		printf("Password too long!\n");
	if (cnt1 != 0 && cnt2 != 0 && cnt3 != 0 && strlen(cpass) >= 8 && strlen(cpass) <= 28)
		return 1;
	else
		return 0;
}
//==========================================================================================
int checkpasswordl(char *cpass) {
	int cnt1 = 0, cnt2 = 0, cnt3 = 0;
	int i = 0;
	for (i = 0; i < strlen(cpass); i++) {

		if (*(cpass + i) >= 'a' && *(cpass + i) <= 'z')
			cnt1++;
		if (*(cpass + i) >= 'A' && *(cpass + i) <= 'Z')
			cnt1++;
		if (*(cpass + i) >= '0' && *(cpass + i) <= '9')
			cnt2++;
		if (*(cpass + i) == '>' || *(cpass + i) == '<' || *(cpass + i) == '_' || *(cpass + i) == '?' || *(cpass + i) == '!')
			cnt3++;
	}
	if (strlen(cpass) > 28)
		if (cnt1 != 0 && cnt2 != 0 && cnt3 != 0 && strlen(cpass) >= 8 && strlen(cpass) <= 28)
			return 1;
		else
			return 0;
}
//=======================================================================================
void ChangePassword(char *pass, char *cpass) {

	char *npass = (char*)malloc(sizeof(char) * 1000000);

	int cnt = 0;

	if (strcmp(pass, cpass) == 0) {
		cnt++;

	}

	if (cnt == 0) {
		printf("Press Password:");
		data_masking(cpass);
	}
	if (cnt != 0 || (checkpasswordl(cpass) && strcmp(pass, encrypt_basic(cpass)) == 0)) {

		printletter();
		printf("\nPress New Password:");

		data_masking(cpass);
		if (checkpassword(cpass)) {
			printf("Press New Password again:");

			data_masking(npass);

			if (strcmp(cpass, npass) == 0) {
				strcpy(pass, encrypt_basic(npass));
				printf("Password Changed!\n\n");

			}
			else {
				while (1) {
					printf("Incorrect Password!\n\n");
					printf("Press New Password again:");
					data_masking(npass);
					if (strcmp(cpass, npass) == 0) {
						strcpy(pass, encrypt_basic(npass));
						printf("Password Changed!\n\n");

						break;
					}
				}
			}
		}
		else {
			printf("Invalid Password\n\n");

			strcpy(cpass, pass);

			ChangePassword(pass, cpass);

		}
	}
	else {
		printf("Invalid Password\n\n");
	}

}
//=======================================================================================
void ValidatePassword(char *pass) {
	char *rpass = (char*)malloc(sizeof(char) * 100000);

	printf("Press Password:");
	data_masking(rpass);

	if (checkpasswordl(rpass)&&strcmp(pass, encrypt_basic(rpass)) == 0)
		printf("Validate Password!\n\n");
	else {

		printf("Password is not collect!!\n\n");
	}

}
//=======================================================================================
int Quit(char *pass) {
	FILE *fp;

	if ((fp = fopen("password.txt", "w")) == NULL) {
		printf("File Open error.\n");
		return -1;
	}

	fprintf(fp, "%s", pass);

	fclose(fp);

	return 0;
}
//=======================================================================================

int main(void) {

	char default_password[100] = "sejong_security_2017!";
	FILE *fp;
	char *pass = (char*)malloc(sizeof(char) * 100000000);
	char *cpass = (char*)malloc(sizeof(char) * 100000000);

	fp = fopen("password.txt", "r");
	if (fp != NULL) {
		fscanf(fp, "%s", pass);
		fclose(fp);
	}
	else {
		strcpy(pass, encrypt_basic(default_password));
	}

	char choice;


	while (1) {
		cpass[0] = '\0';

		printf("Sejong Password Manager:\n\n");
		printf("A. Change Password\n");
		printf("B. Validate Password\n");
		printf("C. Quit\n\n");
		printf("Enter your choice:");

		scanf(" %c", &choice);

		if (choice == 'A' || choice == 'a') {
			ChangePassword(pass, cpass);
		}

		else if (choice == 'B' || choice == 'b') {
			ValidatePassword(pass);
		}

		else if (choice == 'C' || choice == 'c') {
			break;
		}

		else
			printf("Press A or B or C\n\n");
	}

	if (choice == 'C' || choice == 'c') {
		Quit(pass);
	}

	return 0;
}
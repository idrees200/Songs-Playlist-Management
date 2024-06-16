#include<iostream>
#include<fstream>
#include<string>
using namespace std;
class ll {
	class node {
	public:
		string dan;
		string ener;
		string key;
		string loudness;
		string speech;
		string acous;
		string instru;
		int duration;
		string genre;
		string title;
		node* next;
		node(string d="", string e="", string k="", string l="", string s="", string a="", string i="", int du=0, string gen="", string t="") {
			dan = d;
			ener = e;
			key = k;
			loudness = l;
			speech = s;
			acous = a;
			instru = i;
			duration = du;
			genre = gen;
			title = t;

			next = NULL;
		}

	};
public:
	node* head;
	node* tail;
	ll() {
		head = NULL;
		tail = NULL;
	}
	void insertattail(string d, string e, string k, string l, string s, string a, string i, int du, string gen, string t) {
		if (head == NULL) {
			node* temp = new node(d, e, k, l, s, a, i, du, gen, t);
			head = temp;
			tail = temp;
			head->next = tail;
			tail->next = NULL;
		}
		else {
			node* temp = new node(d, e, k, l, s, a, i, du, gen, t);
			tail->next = temp;
			tail = temp;
			tail->next = NULL;

		}

	}
	void insertatanypoint(int ind, string d, string e, string k, string l, string s, string a, string i, int du, string gen, string t) {
		if (ind == 0) {
			int j = 0;
			node* temp = new node();
			temp = head;
			node* mp = new node(d, e, k, l, s, a, i, du, gen, t);
			mp->next = temp;
			head = mp;

		}
		else {
			int j = 0;
			node* temp = new node();
			temp = head;
			node* mp = new node();
			while (j < ind) {
				temp = temp->next;

				j++;
			}
			mp = temp->next;
			node* another = new node(d, e, k, l, s, a, i, du, gen, t);
			temp->next = another;
			another->next = mp;
		}
	}
	void deleteatend() {
		node* temp = new node();
		temp = head;
		node* mp = new node();
		while (temp->next != tail) {
			temp = temp->next;
		}
		mp = tail;
		printname();
		cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
		cout << "CAUTION!!!" << endl;
		cout << "SONG DELETED :" << mp->title << endl;
		cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
		tail = temp;
		tail->next = NULL;
		delete mp;
	}
	void deleteatanypoint(int index) {
		int count = 0;
		node* temp = new node();
		node* temp2 = new node();
		temp = head;
		temp2 = head;
		node* mp = new node();
		mp = head;
		int end;
		while (temp2 != NULL) {
			temp2 = temp2->next;
			count++;
			
		}
		end = count;
		if (index == count) {
			deleteatend();
		}
		if (index == 0) {
			deleteatstart();
		}
		if(index>0&&index<end){
			count = 0;
			while (count < index - 1) {
				count++;
				mp = mp->next;
			}
			count = 0;
			while (count < index) {
				count++;
				temp = temp->next;
			}
			mp->next = temp->next;
			printname();
			cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
			cout << "CAUTION!!!" << endl;
			cout << "SONG DELETED :" << temp->title << endl;
			cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
			delete temp;
		}
	}
	void shuffle() {
		ll list;
		node* temp = new node();
		temp = head;
		int counter = 0;
		while (temp != NULL) {
			if (counter == 3) {
				list.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);
				counter = 0;
			
			}
			temp = temp->next;
			counter++;
				
			
			
		}
		counter = 0;
		temp = head;
		node* st = new node();
		st = list.head;
		int bounter = 0;
		while (st != NULL) {
			st = st->next;
			bounter++;
		}
		st = list.head;
		int check = 0;

		while (temp != NULL) {
			while (st != NULL) {
				if (st->title != temp->title && st->duration != temp->duration) {
					check++;
				}
				st = st->next;
			}
			st = list.head;
			if (check == bounter) {
				list.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);
				check = 0;
			}
			else {
				check = 0;
			}
			temp = temp->next;
			counter++;



		}
		counter = 0;
		temp = head;
		while (temp != NULL) {
			if (counter == 2) {
				list.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);
				counter = 0;

			}
			temp = temp->next;
			counter++;



		}
		
		node* start = new node();
		start = list.head;
	/*	while (start != NULL) {
			cout << start->title << endl;
			start = start->next;
		}
		cout << "____________________" << endl;
		start = head;
		while (start != NULL) {
			cout << start->title << endl;
			start = start->next;
		}*/
		head = list.head;
		tail = list.tail;
	}
	void deleteatstart() {
		node* temp = new node();
		node* mp = new node();
		mp = head;
		temp = head->next;
		head = temp;
		printname();
		cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
		cout << "CAUTION!!!" << endl;
		cout << "SONG DELETED :" << mp->title << endl;
		cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
		delete mp;

	}
	void print() {
		node* temp = new node();
		temp = head;
		int counter = 0;
		while (temp != NULL) {
			cout << "SONG NO :" << counter << endl;
			cout << "SONG NAME :" << temp->title << endl;
			cout << "GENRE :" << temp->genre << endl;
			cout << "DURATION :" << temp->duration << endl;
			cout << "INSTRUMENTALNESS :" << temp->instru << endl;
			cout << "ACOUSTICNESS :" << temp->acous << endl;
			cout << "SPEECHINESS :" << temp->speech << endl;
			cout << "LOUDNESS :" << temp->loudness << endl;
			cout << "KEY :" << temp->key << endl;
			cout << "ENERGY :" << temp->ener << endl;
			cout << "DANCEABILITY :" << temp->dan << endl;
			cout << "-------------------------------------------" << endl;
			cout << "////////////////////////////////////////" << endl;
			cout << "-------------------------------------------" << endl;
			counter++;
			temp = temp->next;

		}
	}
	void printname() {
		node* temp = new node();
		temp = head;
		int counter = 0;
		while (temp != NULL) {
			cout << "SONG NO :" << counter << endl;
			cout << "SONG NAME :" << temp->title << endl;

			counter++;
			temp = temp->next;

		}
	}
	void printdur() {
		node* temp = new node();
		temp = head;
		int counter = 0;
		while (temp != NULL) {
			cout << "SONG NO :" << counter << endl;
			cout << "SONG NAME :" << temp->title << endl;
			cout << "SONG DURATION :" << temp->duration << endl;

			counter++;
			temp = temp->next;

		}
	}

		void sort(){
		
			ll newlist;
			char a = 64;
			node* temp = new node();
			temp = head;
			/*node* start = new node();
			start = head;*/
			while (a< 126) {
				while (temp != NULL) {
					if (temp->title[0] == a) {
						newlist.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);

					}
					temp = temp->next;
				}
				temp = head;
				a = a + 1;

			}
			temp = head;
			a = 32;
			while (a < 64) {
				while (temp != NULL) {
					if (temp->title[0] == a) {
						newlist.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);

					}
					temp = temp->next;
				}
				temp = head;
				a = a + 1;

			}
			head = newlist.head;
			tail = newlist.tail;



		}
		void sortbyd() {
			node* temp = new node();
			temp = head;
			node* start = new node();
			
			node* min = new node();
			string d;
			string eni;
			string kk;
			string ll;
			string sp;
			string a;
			string in;
			int dura;
			string gene;
			string tit;
			
			while (temp != NULL) {
				
				start = temp->next;
				while (start != NULL) {
					if (start->duration < temp->duration) {
						d = temp->dan;
						eni = temp->ener;
						kk = temp->key;
						ll = temp->key;
						sp = temp->speech;
						a = temp->acous;
						in = temp->instru;
						dura = temp->duration;
						gene = temp->genre;
						tit = temp->title;
						temp->dan = start->dan;
						temp->ener= start->ener;
						temp->key = start->key;
						temp->loudness = start->loudness;
						temp->speech = start->speech;
						temp->acous = start->acous;
						temp->instru = start->instru;
						temp->duration = start->duration;
						temp->genre = start->genre;
						temp->title = start->title;

						start->dan=d;
						 start->ener=eni;
						 start->key=kk;
						 start->loudness=ll;
						start->speech=sp;
						start->acous=a;
						start->instru=in;
						start->duration=dura;
						start->genre=gene;
						start->title=tit;
						
					}
					start = start->next;
					
				}
				
			


				temp = temp->next;
			}
			


		}
		void locateatanypoint(int index) {
			node* temp = new node();
			temp = head;
			int counter = 0;
			while (counter != index) {
				counter++;
				temp = temp->next;
			}
			cout << "SONG NO :" << index << endl;
			cout << "SONG NAME :" << temp->title << endl;
			cout << "GENRE :" << temp->genre << endl;
			cout << "DURATION :" << temp->duration << endl;
			cout << "INSTRUMENTALNESS :" << temp->instru << endl;
			cout << "ACOUSTICNESS :" << temp->acous << endl;
			cout << "SPEECHINESS :" << temp->speech << endl;
			cout << "LOUDNESS :" << temp->loudness << endl;
			cout << "KEY :" << temp->key << endl;
			cout << "ENERGY :" << temp->ener << endl;
			cout << "DANCEABILITY :" << temp->dan << endl;
			cout << "-------------------------------------------" << endl;
			cout << "////////////////////////////////////////" << endl;
			cout << "-------------------------------------------" << endl;

		}
		void printf() {
			ofstream yolo("NEWLIST.txt");
			node* temp = new node();
			temp = head;
			int count = 0;
			while (temp != NULL) {
				count++;
				temp = temp->next;
			}
			yolo << count<<endl;
			temp = head;
			for (int i = 0; i < count; i++) {
				
				yolo << "SONG NAME :" << temp->title << endl;
				yolo << "GENRE :" << temp->genre << endl;
				yolo << "DURATION :" << temp->duration << endl;
				yolo << "INSTRUMENTALNESS :" << temp->instru << endl;
				yolo<< "ACOUSTICNESS :" << temp->acous << endl;
				yolo << "SPEECHINESS :" << temp->speech << endl;
				yolo << "LOUDNESS :" << temp->loudness << endl;
				yolo << "KEY :" << temp->key << endl;
				yolo << "ENERGY :" << temp->ener << endl;
				yolo << "DANCEABILITY :" << temp->dan << endl;
				temp = temp->next;
			}
			yolo.close();
		}
		void remd() {
			node* temp = new node();
			temp = head;
			node* start = new node();

			
			node* min = new node();

			while (temp != NULL) {

				start = temp->next;
				while (start != NULL) {

					if (temp->next->title==start->title) {
						
						
						temp->next = temp->next->next;
						

					}
					start = start->next;

				}




				temp = temp->next;
			}

		}
		void sh() {
			node* temp = new node();
			temp = head;
			node* buffer = new node();
			while (temp->next->next->next != NULL) {
				buffer->title = temp->next->next->title;
				buffer->duration = temp->next->next->duration;
				buffer->dan = temp->next->next->dan;
				buffer->loudness = temp->next->next->loudness;
				buffer->acous = temp->next->next->acous;
				buffer->key = temp->next->next->key;
				buffer->speech = temp->next->next->speech;
				buffer->instru = temp->next->next->instru;
				buffer->genre = temp->next->next->genre;
				buffer->ener = temp->next->next->ener;

				temp->next->next->title = temp->title;
				temp->next->next->dan = temp->dan;
				temp->next->next->duration = temp->duration;
				temp->next->next->loudness = temp->loudness;
				temp->next->next->instru = temp->instru;
				temp->next->next->ener = temp->ener;
				temp->next->next->key = temp->key;
				temp->next->next->speech = temp->speech;
				temp->next->next->acous = temp->acous;
				temp->next->next->genre = temp->genre;

				

				temp->title = buffer->title;
				temp->genre = buffer->genre;
				temp->key = buffer->key;
				temp->ener = buffer->ener;
				temp->speech = buffer->speech;
				temp->acous = buffer->acous;
				temp->dan = buffer->dan;
				temp->loudness = buffer->loudness;
				temp->instru = buffer->instru;
				temp->duration = buffer->duration;



				temp = temp->next;
			}



		}
		void rd() {


			ll nl;
			node* temp = new node();
			temp = head;
			node* h = new node();
			int count=0;

			while (temp != NULL) {
				count++;

				temp = temp->next;
			}
			temp = head;
			h = head;
			int co = 0;

			while (temp != NULL) {
				while (h != NULL) {
					if ( h->duration != temp->duration) {
						co++;
						
					}
					/*if (h->title == temp->title) {
						nl.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);


					}*/

			  		/*else {
						nl.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);

					}
				*/
					h = h->next;
				}
				if (co == count-1) {
					nl.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);

				}
				/*if (co != count - 1) {
					nl.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);

				}*/
				h = head;
				co = 0;

				temp = temp->next;
			}
			temp = head;
			h = nl.head;
			while (temp != NULL) {
				while (h != NULL) {
					if ( h->title!=temp->title) {
						co++;

					}
					/*if (h->title == temp->title) {
						nl.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);


					}*/

					/*else {
						nl.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);

					}
				*/
					h = h->next;
				}
				if (co == count ) {
					nl.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);

				}
				/*if (co != count - 1) {
					nl.insertattail(temp->dan, temp->ener, temp->key, temp->loudness, temp->speech, temp->acous, temp->instru, temp->duration, temp->genre, temp->title);

				}*/
				h =nl.head;
				co = 0;

				temp = temp->next;
			}
			head = nl.head;
			tail = nl.tail;
		}
		
};
int main() {
	
	string buffer;
	ll linke;
	int a;
	ifstream yu("Songs Information.csv");
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');

	getline(yu, buffer, ',');

	getline(yu, buffer, ',');
	getline(yu, buffer, '\n');
	
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');

	getline(yu, buffer, ',');

	getline(yu, buffer, ',');
	getline(yu, buffer, '\n');
	
	/*getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');

	yu >> a;
	
	getline(yu, buffer, ',');
	getline(yu, buffer, ',');

	getline(yu, buffer, '\n');*/

	string d;
	string en;
	string ke;
	string loud;
	string spe;
	string aco;
	string inst;
	string durat;
	string gen;
	string tit;
	int count=0;
	while (count<3000) {
		getline(yu, d, ',');
		getline(yu, en, ',');
		getline(yu, ke, ',');
		getline(yu, loud, ',');
		getline(yu, spe, ',');
		getline(yu, aco, ',');
		getline(yu, inst, ',');
		yu >> a;
		getline(yu, durat, ',');
		getline(yu, gen, ',');
		getline(yu, tit, '\n');
		linke.insertattail(d, en, ke, loud, spe, aco, inst, a, gen, tit);
		count++;
	}
	/*linke.sortbyd();
	linke.printdur();*/
	/*cout << "WHERE WOULD YOU LIKE TO INSERT A SONG?" << endl;
	
	cin >> index;
	if(index!=0)
	index = index - 1;
	linke.insertatanypoint(index, d, en, ke, loud, spe, aco, inst, durat, gen, tit);*/
	/*linke.deleteatstart();
	linke.deleteatend();*/
	//cout << "WHERE WOULD YOU LIKE TO DEL A SONG?" << endl;
	//int index;
	//cin >> index;
	
	//linke.deleteatanypoint(index);
	//cout << "___________" << endl;
	///*linke.shuffle();
	//linke.sort();
	//linke.printname();*/
	//linke.sortbyd();
	int indexi;
	int choice =00;
	int ind;
	int chose;
	int chouse;
	int cooose;
	int eer;
	int eri;
	do{
		cout << "                                SONGSIMA                                    " << endl;
		cout << "                                                                                       " << endl;
		cout << "WHICH OPTION DO YOU WANT TO SELECT !" << endl;
		cout << "01.VIEW SONG PLAYLIST" << endl;
		if (choice == 1) {
			linke.printname();
			do {
				cout << "WHICH OPTION DO YOU WANT TO SELECT !" << endl;
				cout << "01.PLAY SONGS" << endl;
				cout << "02.SORT" << endl;
				cout << "03.INSERT ANY SONG" << endl;
				cout << "04.DELETE ANY SONG " << endl;
				cout << "05.SHUFFLE AND REMOVE DUPLICATES" << endl;
				cout << "06.SAVE NEW PLAY LIST IN FILE" << endl;
				cout << "07.SHUFFLE " << endl;
				cout << "08.REMOVE DUPLICATES" << endl;
				cout << "PRESS -1 TO EXIT" << endl;
				do {
					cin >> chouse;
					/*if (chose == -1)
						break;*/
					if (chouse != 1 && chouse != 2 && chouse != 3 && chouse != -1 && chouse != 4 && chouse != 5 && chouse != 6&&chouse!=7 &&chouse!=8) {
						cout << "INVALID CHOICE! TRY AGAIN!" << endl;
					}
				} while (chouse != 1 && chouse != 2 && chouse != 3 && chouse != -1 && chouse != 4 && chouse != 5&&chouse!=6 && chouse != 7&&chouse!=8);
				if (chouse == 7) {
					linke.sh();
					linke.printname();
				}
				if (chouse == 8) {
					linke.rd();
					linke.printname();
				}

				if (chouse == 6) {
					
					linke.printf();
					cout << "FILE SAVED SUCCESFULLY" << endl;
				}
				if (chouse == 5) {
					linke.shuffle();
					linke.printname();
					cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
					cout << "CAUTION!!!" << endl;
					cout << "SONGS ARE SHUFFLED AND DUPLICATES ARE REMOVED" << endl;
					cout << "¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬¬" << endl;
					
				}
				if (chouse == 4) {
					do {
						cout << "WHERE DO YOU WANT TO DELETE SONG" << endl;
						cout << "01.START OF THE PLAYLIST" << endl;
						cout << "02.END OF THE PLAYLIST" << endl;
						cout << "03.ANYWHERE IN THE MIDDLE" << endl;
						cout << "-1.EXIT/BACK" << endl;
						do {
							cin >> eri;
							/*if (chose == -1)
								break;*/
							if (eri != 1 && eri != 2 && eri != 3 && eri != -1) {
								cout << "INVALID CHOICE! TRY AGAIN!" << endl;
							}
						} while (eri != 1 && eri != 2 && eri != 3 && eri != -1);
						if (eri == 1) {
							linke.deleteatstart();

						}
						if (eri == 2) {
							linke.deleteatend();
						}
						if (eri == 3) {
							int indi;
							cout << "WHERE DO YOU WANT TO DELETE SONG" << endl;
							cin >> indi;
							linke.deleteatanypoint(indi);
						}
					} while (eri != -1);
				}
				if (chouse == 3) {
					do {
						cout << "WHERE DO YOU WANT TO INSERT SONG" << endl;
						cout << "01.START OF THE PLAYLIST" << endl;
						cout << "02.END OF THE PLAYLIST" << endl;
						cout << "03.ANYWHERE IN THE MIDDLE" << endl;
						cout << "-1.EXIT/BACK" << endl;
						do {
							cin >> eer;
							/*if (chose == -1)
								break;*/
							if (eer != 1 && eer != 2 && eer != 3 && eer != -1) {
								cout << "INVALID CHOICE! TRY AGAIN!" << endl;
							}
						} while (eer != 1 && eer != 2 && eer != 3 && eer != -1);

						if (eer == 1) {
							cout << "ENTER TITLE OF THE SONG" << endl;
							getline(cin, tit);
							getline(cin, tit);
							cout << "ENTER DURATION OF THE SONG" << endl;
							cin >> a;
							cout << "ENTER DANCEABILITY OF THE SONG" << endl;
							getline(cin, d);
							getline(cin, d);
							cout << "ENTER KEY OF THE SONG" << endl;
							getline(cin, ke);
							cout << "ENTER GENRE OF THE SONG" << endl;
							getline(cin, gen);
							cout << "ENTER ACOUSTICS OF THE SONG" << endl;
							getline(cin, aco);
							cout << "ENTER ENERGY OF THE SONG" << endl;
							getline(cin, en);
							cout << "ENTER INSTRUMENTALS OF THE SONG" << endl;
							getline(cin, inst);
							cout << "ENTER SPEECHINESS OF THE SONG" << endl;
							getline(cin, spe);
							cout <<  "ENTER LOUDNESS OF THE SONG" << endl;
							getline(cin, loud);
							linke.insertatanypoint(0, d, en, ke, loud, spe, aco, inst, a, gen, tit);
							linke.printname();
						}
						if (eer == 2) {
							cout << "ENTER TITLE OF THE SONG" << endl;
							getline(cin, tit);
							getline(cin, tit);
							cout << "ENTER DURATION OF THE SONG" << endl;
							cin >> a;
							cout << "ENTER DANCEABILITY OF THE SONG" << endl;
							getline(cin, d);
							getline(cin, d);
							cout << "ENTER KEY OF THE SONG" << endl;
							getline(cin, ke);
							cout << "ENTER GENRE OF THE SONG" << endl;
							getline(cin, gen);
							cout << "ENTER ACOUSTICS OF THE SONG" << endl;
							getline(cin, aco);
							cout << "ENTER ENERGY OF THE SONG" << endl;
							getline(cin, en);
							cout << "ENTER INSTRUMENTALS OF THE SONG" << endl;
							getline(cin, inst);
							cout << "ENTER SPEECHINESS OF THE SONG" << endl;
							getline(cin, spe);
							cout << "ENTER LOUDNESS OF THE SONG" << endl;
							getline(cin, loud);
							linke.insertattail( d, en, ke, loud, spe, aco, inst, a, gen, tit);
							linke.printname();
						}
						if (eer == 3) {
							cout << "WHERE DO YOU WANT TO INSERT?" << endl;
							cin >> indexi;
							cout << "ENTER TITLE OF THE SONG" << endl;
							getline(cin, tit);
							getline(cin, tit);
							cout << "ENTER DURATION OF THE SONG" << endl;
							cin >> a;
							cout << "ENTER DANCEABILITY OF THE SONG" << endl;
							getline(cin, d);
							getline(cin, d);
							cout << "ENTER KEY OF THE SONG" << endl;
							getline(cin, ke);
							cout << "ENTER GENRE OF THE SONG" << endl;
							getline(cin, gen);
							cout << "ENTER ACOUSTICS OF THE SONG" << endl;
							getline(cin, aco);
							cout << "ENTER ENERGY OF THE SONG" << endl;
							getline(cin, en);
							cout << "ENTER INSTRUMENTALS OF THE SONG" << endl;
							getline(cin, inst);
							cout << "ENTER SPEECHINESS OF THE SONG" << endl;
							getline(cin, spe);
							cout << "ENTER LOUDNESS OF THE SONG" << endl;
							getline(cin, loud);
							if (indexi != 0) {
								indexi = indexi - 1;
							}
							linke.insertatanypoint(indexi,d, en, ke, loud, spe, aco, inst, a, gen, tit);
							
							linke.printname();
						}
					} while (eer != -1);
				}
				if (chouse == 2) {
					do {
						cout << "SORT BY ?" << endl;
						cout << "01.DURATION" << endl;
						cout << "02.SONG TITLE" << endl;
						cout << "-1.EXIT/BACK" << endl;
						do {
							cin >> cooose;
							/*if (chose == -1)
								break;*/
							if (cooose != 1 && cooose != 2 && cooose != -1 ) {
								cout << "INVALID CHOICE! TRY AGAIN!" << endl;
							}
						} while (chouse != 1 && chouse != 2  && chouse != -1);
						if (cooose == 2) {
							linke.sort();
							linke.printname();
						}
						if (cooose == 1) {
							linke.sortbyd();
							linke.printdur();
						}

					} while (cooose != 1 && cooose != 2);
				}
				if (chouse == 1) {
					do {
						cout << "SELECT THE SONG OF WHICH YOU WANT TO SEE META DATA OF OR PRESS -1 TO EXIT" << endl;

						cin >> ind;
						if (ind > -1) {
							do {
								cout << "__________" << endl;
								cout << "PLAYING : ";
								
								linke.locateatanypoint(ind);
								cout << "OPTIONS :" << endl;
								cout << "01.PLAY NEXT" << endl;
								cout << "02.PLAY ON REPEAT" << endl;
								cout << "03.PLAY PREVIOUS" << endl;
								cout << "-1.EXIT/BACK" << endl;

								do {
									cin >> chose;
									/*if (chose == -1)
										break;*/
									if (chose != 1 && chose != 2 && chose != 3 && chose != -1) {
										cout << "INVALID CHOICE! TRY AGAIN!" << endl;
									}
								} while (chose != 1 && chose != 2 && chose != 3 && chose != -1);
								if (chose == 1) {
									ind = ind + 1;
									cout << "__________" << endl;
									cout << "PLAYING : ";
									linke.locateatanypoint(ind);
								}
								if (chose == 2) {
									ind = ind;
									cout << "__________" << endl;
									cout << "PLAYING : ";
									linke.locateatanypoint(ind);
								}
								if (chose == 3) {
									ind = ind - 1;
									cout << "__________" << endl;
									cout << "PLAYING : ";
									linke.locateatanypoint(ind);
								}

							} while (chose != -1);
						}

					} while (ind != -1);
				}
			} while (chouse != -1);
		}
		cin >> choice;
	
	} while (choice != -1);
	return 0;
}
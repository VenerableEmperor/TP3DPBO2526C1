#include <bits/stdc++.h>
#include "Device.cpp"

using namespace std;

void title(){
	cout << "==============================================\n";
	cout << "||       SMART HOME DEVICE MANAGER!         ||\n";
	cout << "==============================================\n";
	cout << "\n";
}

void helpmenu(){
	cout << "==============================================\n";
	cout << "||              COMMAND LIST                ||\n";
	cout << "||                 +INPUT                   ||\n";
	cout << "||                 +SHOW                    ||\n";
	cout << "||                 +UPDATE                  ||\n";
	cout << "||                 +DELETE                  ||\n";
	cout << "||                 +SEARCH                  ||\n";
	cout << "||                 +HELP                    ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT INPUT :                          ||\n";
	cout << "||INPUT tipe(LIGHT/THERMO/SPEAKER) id nama  ||\n";
	cout << "||value                                     ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT SHOW :                           ||\n";
	cout << "||SHOW                                      ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT UPDATE :                         ||\n";
	cout << "||UPDATE id nama value                      ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT DELETE :                         ||\n";
	cout << "||DELETE id                                 ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT SEARCH :                         ||\n";
	cout << "||SEARCH id                                 ||\n";
	cout << "||                                          ||\n";
	cout << "||+ FORMAT HELP :                           ||\n";
	cout << "||HELP                                      ||\n";
	cout << "==============================================\n";
}

SmartDevice* search(string id, SmartDevice* datadevice[], int jumlah){
	for (int i = 0; i < jumlah; i++){
		if (datadevice[i]->getId() == id){ 
			return datadevice[i];
		}
	}
	return nullptr; 
}

bool updateDevice(string id, SmartDevice* datadevice[], int jumlah, string newname, int newval){
	bool terupdate = false;
	for (int i = 0; i < jumlah; i++){
		if (datadevice[i]->getId() == id){ 
			datadevice[i]->setName(newname);
			datadevice[i]->setVal(newval);
			terupdate = true;
		}
	} 
	return terupdate;
}

bool deleteDevice(string id, SmartDevice* datadevice[], int *jumlah){
	bool ketemu = false;
	for (int i = 0; i < *jumlah; i++) {
		if (datadevice[i]->getId() == id) {
			ketemu = true;
			delete datadevice[i];
			for (int j = i; j < *jumlah - 1; j++) {
				datadevice[j] = datadevice[j+1];
			}
			datadevice[*jumlah - 1] = nullptr; 
			*jumlah = *jumlah - 1; 
			break;
		}
	}
	return ketemu;
}

void hitungpanjang(int *pid, int *pname, int *ptype, int *pval, SmartDevice* datadevice[], int jumlah){
	for (int i = 0; i < jumlah; i++){
		int idlen = datadevice[i]->getId().length();
		int namelen = datadevice[i]->getName().length();
		int typelen = datadevice[i]->getType().length();
		int vallen = to_string(datadevice[i]->getVal()).length();
		if (idlen > *pid){
			*pid = idlen;
		}
		if (namelen > *pname) {
			*pname = namelen;
		}
		if (typelen > *ptype) {
			*ptype = typelen;
		}
		if (vallen > *pval) {
			*pval = vallen;
		}
	}
}

void judul(int pid, int pname, int ptype, int pval, int pall){
	for (int j = 0; j < pall; j++){
		cout << "=";
	}
	cout << "\n";

	float sid = (pid + 1 - 2);
	cout << "|";
	cout << "ID";
	for (int j = 0; j < round(sid);j++){
		cout << " ";
	}

	float sname = (pname + 1 - 11);
	cout << "|";
	cout << "DEVICE NAME";
	for (int j = 0; j < round(sname);j++){
		cout << " ";
	}

	float stype = (ptype + 1 - 11);
	cout << "|";
	cout << "DEVICE TYPE";
	for (int j = 0; j < round(stype);j++){
		cout << " ";
	}

	float sval = (pval + 1 - 5);
	cout << "|";
	cout << "VALUE";
	for (int j = 0; j < round(sval);j++){
		cout << " ";
	}
	cout << "|\n";
	for (int j = 0; j < pall; j++){
		cout << "=";
	}
	cout << "\n";
}

void showall(SmartDevice* datadevice[], int jumlah){
	cout << "\n";
	int pid = 2;
	int pname = 11;
	int ptype = 11;
	int pval = 5;
	hitungpanjang(&pid, &pname, &ptype, &pval, datadevice, jumlah);
	int pall = pid + pname + ptype + pval + 9;
	judul(pid, pname, ptype, pval, pall);
	
	for (int i = 0; i < jumlah; i++){
		float sid = (pid + 1 - datadevice[i]->getId().length());
		cout << "|";
		cout << datadevice[i]->getId();
		for (int j = 0; j < round(sid);j++){
			cout << " ";
		}

		float sname = (pname + 1 - datadevice[i]->getName().length());
		cout << "|";
		cout << datadevice[i]->getName();
		for (int j = 0; j < round(sname);j++){
			cout << " ";
		}

		float stype = (ptype + 1 - datadevice[i]->getType().length());
		cout << "|";
		cout << datadevice[i]->getType();
		for (int j = 0; j < round(stype);j++){
			cout << " ";
		}

		float sval = (pval + 1 - to_string(datadevice[i]->getVal()).length());
		cout << "|";
		cout << datadevice[i]->getVal();
		for (int j = 0; j < round(sval);j++){
			cout << " ";
		}
		cout << "|\n";
	}
	for (int j = 0; j < pall; j++){
		cout << "=";
	}
	cout << "\n\n";
}

void hitungpanjangsatu(int *pid, int *pname, int *ptype, int *pval, SmartDevice* datadevice){
	int idlen = datadevice->getId().length();
	int namelen = datadevice->getName().length();
	int typelen = datadevice->getType().length();
	int vallen = to_string(datadevice->getVal()).length();
	if (idlen > *pid){
		*pid = idlen;
	}
	if (namelen > *pname) {
		*pname = namelen;
	}
	if (typelen > *ptype) {
		*ptype = typelen;
	}
	if (vallen > *pval) {
		*pval = vallen;
	}
}

void showsatu(SmartDevice* datadevice){
	cout << "\n";
	int pid = 2;
	int pname = 11;
	int ptype = 11;
	int pval = 5;
	hitungpanjangsatu(&pid, &pname, &ptype, &pval, datadevice);
	int pall = pid + pname + ptype + pval + 9;
	judul(pid, pname, ptype, pval, pall);

	float sid = (pid + 1 - datadevice->getId().length());
	cout << "|";
	cout << datadevice->getId();
	for (int j = 0; j < round(sid);j++){
		cout << " ";
	}

	float sname = (pname + 1 - datadevice->getName().length());
	cout << "|";
	cout << datadevice->getName();
	for (int j = 0; j < round(sname);j++){
		cout << " ";
	}

	float stype = (ptype + 1 - datadevice->getType().length());
	cout << "|";
	cout << datadevice->getType();
	for (int j = 0; j < round(stype);j++){
		cout << " ";
	}

	float sval = (pval + 1 - to_string(datadevice->getVal()).length());
	cout << "|";
	cout << datadevice->getVal();
	for (int j = 0; j < round(sval);j++){
		cout << " ";
	}
	cout << "|\n";

	for (int j = 0; j < pall; j++){
		cout << "=";
	}
	cout << "\n\n";
}

void clearcin(){
	cin.clear();
	cin.ignore(numeric_limits<streamsize>::max(),'\n');
}

int main(){
	title();
	helpmenu();
	SmartDevice* datadevice[99];
	for(int i = 0; i < 99; i++) {
		datadevice[i] = nullptr;
	}
	int jumlah = 0;
	string input;
	
	do { 
		cout << "INPUT : ";
		cin >> input;
		if (input != "EXIT"){ 
			string id; 
			if (input == "INPUT"){
				string type, name;
				int val;
				cin >> type >> id >> name >> val;
				
				if (type == "LIGHT"){
					datadevice[jumlah] = new SmartLight(id, name, val);
				} else if (type == "THERMO") {
					datadevice[jumlah] = new SmartThermostat(id, name, val);
				} else if (type == "SPEAKER") {
					datadevice[jumlah] = new SmartSpeaker(id, name, val);
				} else {
					datadevice[jumlah] = new SmartLight(id, name, val);
				}
				jumlah += 1;
			}
			else if (input == "SHOW"){
				showall(datadevice, jumlah);
			}
			else if (input == "UPDATE"){
				cin >> id;
				string name;
				int val;
				cin >> name >> val;
				
				bool akhir = updateDevice(id, datadevice, jumlah, name, val);
				if (akhir == true){
					cout << "DATA DEVICE BERHASIL DIUPDATE!\n";
				}
				else {
					cout << "DATA DEVICE GAGAL DIUPDATE!\n";
				}
			}
			else if (input == "DELETE"){
				cin >> id; 
				bool hasil = deleteDevice(id, datadevice, &jumlah);
				if (hasil == true) {
					cout << "DEVICE YANG DIPILIH BERHASIL DIHAPUS!\n"; 
				}
				else {
					cout << "DEVICE YANG DIPILIH GAGAL DIHAPUS!\n"; 
				}
			}
			else if (input == "SEARCH"){
				cin >> id; 
				SmartDevice* cari = search(id, datadevice, jumlah);
				if (cari != nullptr) {
					showsatu(cari);
				}
				else { 
					cout << "ID DEVICE TIDAK COCOK DENGAN MANAPUN!\n";
				}
			}
			else if (input == "HELP"){
				helpmenu();
			}
			else {
				cout << "COMMAND INVALID!\n";
			}
		}
		clearcin();
	} while (input != "EXIT");
	
	for(int i = 0; i < jumlah; i++){
		delete datadevice[i];
	}
	
	return 0; 
}
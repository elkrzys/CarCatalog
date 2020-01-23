#ifndef MAKEREPORT_H
#define MAKEREPORT_H
#include"ReadFile.h"
#include"Model.h"
class MakeReport : public ReadFile{
	std::string clientName;
	std::string clientSname;
	int day;
	int month;
	int year;
	int clientPhoneNumber;
	std::string email;
	//dane z leasingu
	int period = 0;
	int mileage = 0;
	float ownc = 0;
	float rate = 0;
public:
	MakeReport(std::string);
	int setRepDetails(int, int, float, float);
	void appNewReport(Model&);
	friend std::ostream& operator << (std::ostream&, MakeReport&);
};

#endif

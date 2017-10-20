#include "../Public/PopularContact.h"


//begin namespace block
namespace COMMON
{

PopularContact::PopularContact()
{
	this->_ConstructorID = 1558266229;
}

PopularContact::PopularContact(unsigned long long client_id, int32 importers)
{
	this->_ConstructorID = 1558266229;
	this->client_id = client_id;
	this->importers = importers;
}
void PopularContact::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->client_id);
	Writer.WriteInt(this->importers);
}


void PopularContact::OnResponce(BinaryReader& Reader)
{
	client_id = Reader.ReadLong();
	importers = Reader.ReadInt();
	this->_Responded = true;
}
PopularContact::~PopularContact()
{
}
}//end namespace block

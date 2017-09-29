#include "../Public/GetContacts.h"


//begin namespace block
namespace CONTACTS
{

GetContacts::GetContacts()
{
	this->_ConstructorID = -1071414113;
	this->_ContentRelated = true;
}

GetContacts::GetContacts(int32 hash)
{
	this->_ConstructorID = -1071414113;
	this->_ContentRelated = true;
	this->hash = hash;
}
void GetContacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->hash);
}


void GetContacts::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CONTACTS::Contacts*>(Reader.TGReadObject());
	this->_Responded = true;
}
GetContacts::~GetContacts()
{

}
}//end namespace block

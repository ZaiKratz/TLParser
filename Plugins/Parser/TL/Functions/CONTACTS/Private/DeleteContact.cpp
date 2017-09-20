#include "../Public/DeleteContact.h"


//begin namespace block
namespace CONTACTS
{

DeleteContact::DeleteContact()
{
	this->_ConstructorID = 1144493454;
	this->_ContentRelated = true;
}

DeleteContact::DeleteContact(COMMON::InputUser* id)
{
	this->_ConstructorID = 1144493454;
	this->_ContentRelated = true;
	this->id = id;
}
void DeleteContact::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->id->OnSend(Writer);
}


void DeleteContact::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CONTACTS::Link*>(Reader.TGReadObject());
}
DeleteContact::~DeleteContact()
{

}
}//end namespace block

#include "../Public/ImportContacts.h"


//begin namespace block
namespace CONTACTS
{

ImportContacts::ImportContacts()
{
	this->_ConstructorID = 746589157;
	this->_ContentRelated = true;
}

ImportContacts::ImportContacts(TArray<TLBaseObject*>  contacts)
{
	this->_ConstructorID = 746589157;
	this->_ContentRelated = true;
	this->contacts = contacts;
}
void ImportContacts::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->contacts.Num());
	for(auto X : this->contacts)
	{
	X->OnSend(Writer);
	}
}


void ImportContacts::OnResponce(BinaryReader& Reader)
{
	this->result = reinterpret_cast<CONTACTS::ImportedContacts*>(Reader.TGReadObject());
	this->_Responded = true;
}
ImportContacts::~ImportContacts()
{
	if(this->result)
	{
		delete this->result;
	}
}
}//end namespace block

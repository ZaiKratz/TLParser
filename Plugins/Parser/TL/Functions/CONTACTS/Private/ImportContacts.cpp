#include "../Public/ImportContacts.h"


//begin namespace block
namespace CONTACTS
{

ImportContacts::ImportContacts()
{
	this->_ConstructorID = -452231124;
	this->_ContentRelated = true;
}

ImportContacts::ImportContacts(TArray<PRIVATE::InputContact*> contacts)
{
	this->_ConstructorID = -452231124;
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
}
ImportContacts::~ImportContacts()
{

}
}//end namespace block

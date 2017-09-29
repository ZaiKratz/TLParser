#include "../Public/ImportedContact.h"


//begin namespace block
namespace COMMON
{

ImportedContact::ImportedContact()
{
	this->_ConstructorID = -805141448;
}

ImportedContact::ImportedContact(int32 user_id, unsigned long long client_id)
{
	this->_ConstructorID = -805141448;
	this->user_id = user_id;
	this->client_id = client_id;
}
void ImportedContact::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.WriteLong(this->client_id);
}


void ImportedContact::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	client_id = Reader.ReadLong();
	this->_Responded = true;
}
ImportedContact::~ImportedContact()
{

}
}//end namespace block

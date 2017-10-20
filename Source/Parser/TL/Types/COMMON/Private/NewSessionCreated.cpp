#include "../Public/NewSessionCreated.h"


//begin namespace block
namespace COMMON
{

NewSessionCreated::NewSessionCreated()
{
	this->_ConstructorID = -1631450872;
}

NewSessionCreated::NewSessionCreated(unsigned long long first_msg_id, unsigned long long unique_id, unsigned long long server_salt)
{
	this->_ConstructorID = -1631450872;
	this->first_msg_id = first_msg_id;
	this->unique_id = unique_id;
	this->server_salt = server_salt;
}
void NewSessionCreated::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->first_msg_id);
	Writer.WriteLong(this->unique_id);
	Writer.WriteLong(this->server_salt);
}


void NewSessionCreated::OnResponce(BinaryReader& Reader)
{
	first_msg_id = Reader.ReadLong();
	unique_id = Reader.ReadLong();
	server_salt = Reader.ReadLong();
	this->_Responded = true;
}
NewSessionCreated::~NewSessionCreated()
{
}
}//end namespace block

#include "../Public/BadServerSalt.h"


//begin namespace block
namespace COMMON
{

BadServerSalt::BadServerSalt()
{
	this->_ConstructorID = 2068098029;
}

BadServerSalt::BadServerSalt(unsigned long long bad_msg_id, int32 bad_msg_seqno, int32 error_code, unsigned long long new_server_salt)
{
	this->_ConstructorID = 2068098029;
	this->bad_msg_id = bad_msg_id;
	this->bad_msg_seqno = bad_msg_seqno;
	this->error_code = error_code;
	this->new_server_salt = new_server_salt;
}
void BadServerSalt::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteLong(this->bad_msg_id);
	Writer.WriteInt(this->bad_msg_seqno);
	Writer.WriteInt(this->error_code);
	Writer.WriteLong(this->new_server_salt);
}


void BadServerSalt::OnResponce(BinaryReader& Reader)
{
	bad_msg_id = Reader.ReadLong();
	bad_msg_seqno = Reader.ReadInt();
	error_code = Reader.ReadInt();
	new_server_salt = Reader.ReadLong();
}
BadServerSalt::~BadServerSalt()
{

}
}//end namespace block

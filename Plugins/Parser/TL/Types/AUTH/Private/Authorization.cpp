#include "../Public/Authorization.h"


//begin namespace block
namespace AUTH
{

Authorization::Authorization()
{
	this->_ConstructorID = 369690061;
}

Authorization::Authorization(int32 tmp_sessions, COMMON::User* user)
{
	this->_ConstructorID = 369690061;
	this->tmp_sessions = tmp_sessions;
	this->user = user;
}
void Authorization::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	//Calculate the flags. This equals to those flag arguments which are NOT None
	int32 Flags = 0;
	if(!tmp_sessions)
	{
		Flags |= (1 << 0);
	}
	else
	{
		Flags |= 0;
	}
	Writer.WriteInt(Flags);

	if(!this->tmp_sessions)
	{
	Writer.WriteInt(this->tmp_sessions);
	}
	this->user->OnSend(Writer);
}


void Authorization::OnResponce(BinaryReader& Reader)
{
	auto Flags = Reader.ReadInt();

	if((Flags & (1 << 0)) != 0) 
	{
	tmp_sessions = Reader.ReadInt();
	}
	user = reinterpret_cast<COMMON::User*>(Reader.TGReadObject());
}
Authorization::~Authorization()
{

}
}//end namespace block

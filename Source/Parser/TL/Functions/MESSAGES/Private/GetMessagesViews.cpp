#include "../Public/GetMessagesViews.h"


//begin namespace block
namespace MESSAGES
{

GetMessagesViews::GetMessagesViews()
{
	this->_ConstructorID = -993483427;
	this->_ContentRelated = true;
}

GetMessagesViews::GetMessagesViews(TLBaseObject*  peer, TArray<int32>  id, bool increment)
{
	this->_ConstructorID = -993483427;
	this->_ContentRelated = true;
	this->peer = peer;
	this->id = id;
	this->increment = increment;
}
void GetMessagesViews::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	this->peer->OnSend(Writer);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->id.Num());
	for(auto X : this->id)
	{
	Writer.WriteInt(X);
	}
	Writer.WriteBool(this->increment);
}


void GetMessagesViews::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();
	int32 Count = Reader.ReadInt();
	for(int32 i = 0; i < Count; i++)
	{
		this->result.Add(Reader.ReadInt());
	}
	this->_Responded = true;
}
GetMessagesViews::~GetMessagesViews()
{
	if(this->peer)
	{
		delete this->peer;
	}
}
}//end namespace block

#include "../Public/UpdateDeleteMessages.h"


//begin namespace block
namespace COMMON
{

UpdateDeleteMessages::UpdateDeleteMessages()
{
	this->_ConstructorID = -441447006;
}

UpdateDeleteMessages::UpdateDeleteMessages(TArray<int32> messages, int32 pts, int32 pts_count)
{
	this->_ConstructorID = -441447006;
	this->messages = messages;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateDeleteMessages::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->messages.Num());
	for(auto X : this->messages)
	{
	Writer.WriteInt(X);
	}
	Writer.WriteInt(this->pts);
	Writer.WriteInt(this->pts_count);
}


void UpdateDeleteMessages::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len24396 = Reader.ReadInt();
	for(int32 i = 0; i < Len24396; i++)
	{
	auto X = Reader.ReadInt();
	messages.Add(X);
	}
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
}
UpdateDeleteMessages::~UpdateDeleteMessages()
{

}
}//end namespace block

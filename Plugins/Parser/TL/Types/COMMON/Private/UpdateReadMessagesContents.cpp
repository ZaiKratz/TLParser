#include "../Public/UpdateReadMessagesContents.h"


//begin namespace block
namespace COMMON
{

UpdateReadMessagesContents::UpdateReadMessagesContents()
{
	this->_ConstructorID = 859423080;
}

UpdateReadMessagesContents::UpdateReadMessagesContents(TArray<int32> messages, int32 pts, int32 pts_count)
{
	this->_ConstructorID = 859423080;
	this->messages = messages;
	this->pts = pts;
	this->pts_count = pts_count;
}
void UpdateReadMessagesContents::OnSend(BinaryWriter& Writer)
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


void UpdateReadMessagesContents::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len1295 = Reader.ReadInt();
	for(int32 i = 0; i < Len1295; i++)
	{
	auto X = Reader.ReadInt();
	messages.Add(X);
	}
	pts = Reader.ReadInt();
	pts_count = Reader.ReadInt();
}
UpdateReadMessagesContents::~UpdateReadMessagesContents()
{

}
}//end namespace block

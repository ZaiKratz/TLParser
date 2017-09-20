#include "../Public/ChatsSlice.h"


//begin namespace block
namespace MESSAGES
{

ChatsSlice::ChatsSlice()
{
	this->_ConstructorID = 1142020252;
}

ChatsSlice::ChatsSlice(int32 count, TArray<COMMON::Chat*> chats)
{
	this->_ConstructorID = 1142020252;
	this->count = count;
	this->chats = chats;
}
void ChatsSlice::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->count);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->chats.Num());
	for(auto X : this->chats)
	{
	X->OnSend(Writer);
	}
}


void ChatsSlice::OnResponce(BinaryReader& Reader)
{
	count = Reader.ReadInt();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len3809 = Reader.ReadInt();
	for(int32 i = 0; i < Len3809; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
}
ChatsSlice::~ChatsSlice()
{

}
}//end namespace block
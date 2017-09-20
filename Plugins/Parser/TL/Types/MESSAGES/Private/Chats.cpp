#include "../Public/Chats.h"


//begin namespace block
namespace MESSAGES
{

Chats::Chats()
{
	this->_ConstructorID = -710934684;
}

Chats::Chats(TArray<COMMON::Chat*> chats)
{
	this->_ConstructorID = -710934684;
	this->chats = chats;
}
void Chats::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->chats.Num());
	for(auto X : this->chats)
	{
	X->OnSend(Writer);
	}
}


void Chats::OnResponce(BinaryReader& Reader)
{
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len7764 = Reader.ReadInt();
	for(int32 i = 0; i < Len7764; i++)
	{
	auto X = reinterpret_cast<COMMON::Chat*>(Reader.TGReadObject());
	chats.Add(X);
	}
}
Chats::~Chats()
{

}
}//end namespace block

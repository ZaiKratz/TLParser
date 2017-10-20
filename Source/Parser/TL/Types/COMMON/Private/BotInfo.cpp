#include "../Public/BotInfo.h"


//begin namespace block
namespace COMMON
{

BotInfo::BotInfo()
{
	this->_ConstructorID = -1729618630;
}

BotInfo::BotInfo(int32 user_id, FString description, TArray<COMMON::BotCommand*>  commands)
{
	this->_ConstructorID = -1729618630;
	this->user_id = user_id;
	this->description = description;
	this->commands = commands;
}
void BotInfo::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.WriteInt(this->user_id);
	Writer.TGWriteString(this->description);
	Writer.WriteInt(0x1cb5c415);
	Writer.WriteInt(this->commands.Num());
	for(auto X : this->commands)
	{
	X->OnSend(Writer);
	}
}


void BotInfo::OnResponce(BinaryReader& Reader)
{
	user_id = Reader.ReadInt();
	description = Reader.TGReadString();
	Reader.ReadInt();

	//Len concatenated with rand number to get rid of confusions with redefinition
	int32 Len17167 = Reader.ReadInt();
	for(int32 i = 0; i < Len17167; i++)
	{
	auto X = reinterpret_cast<COMMON::BotCommand*>(Reader.TGReadObject());
	commands.Add(X);
	}
	this->_Responded = true;
}
BotInfo::~BotInfo()
{
}
}//end namespace block

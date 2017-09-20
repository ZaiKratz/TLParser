#include "../Public/BotCommand.h"


//begin namespace block
namespace COMMON
{

BotCommand::BotCommand()
{
	this->_ConstructorID = -943162686;
}

BotCommand::BotCommand(FString command, FString description)
{
	this->_ConstructorID = -943162686;
	this->command = command;
	this->description = description;
}
void BotCommand::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->command);
	Writer.TGWriteString(this->description);
}


void BotCommand::OnResponce(BinaryReader& Reader)
{
	command = Reader.TGReadString();
	description = Reader.TGReadString();
}
BotCommand::~BotCommand()
{

}
}//end namespace block
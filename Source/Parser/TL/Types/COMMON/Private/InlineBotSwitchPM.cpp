#include "../Public/InlineBotSwitchPM.h"


//begin namespace block
namespace COMMON
{

InlineBotSwitchPM::InlineBotSwitchPM()
{
	this->_ConstructorID = 1008755359;
}

InlineBotSwitchPM::InlineBotSwitchPM(FString text, FString start_param)
{
	this->_ConstructorID = 1008755359;
	this->text = text;
	this->start_param = start_param;
}
void InlineBotSwitchPM::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteString(this->text);
	Writer.TGWriteString(this->start_param);
}


void InlineBotSwitchPM::OnResponce(BinaryReader& Reader)
{
	text = Reader.TGReadString();
	start_param = Reader.TGReadString();
	this->_Responded = true;
}
InlineBotSwitchPM::~InlineBotSwitchPM()
{

}
}//end namespace block

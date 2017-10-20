#include "../Public/InputReportReasonSpam.h"


//begin namespace block
namespace COMMON
{

InputReportReasonSpam::InputReportReasonSpam()
{
	this->_ConstructorID = 1490799288;
}
void InputReportReasonSpam::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputReportReasonSpam::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputReportReasonSpam::~InputReportReasonSpam()
{
}
}//end namespace block

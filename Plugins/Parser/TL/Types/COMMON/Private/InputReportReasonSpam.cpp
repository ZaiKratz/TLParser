#include "../Public/InputReportReasonSpam.h"


//begin namespace block
namespace COMMON
{

InputReportReasonSpam::InputReportReasonSpam()
{
	this->_ConstructorID = -1194665128;
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
}
InputReportReasonSpam::~InputReportReasonSpam()
{

}
}//end namespace block

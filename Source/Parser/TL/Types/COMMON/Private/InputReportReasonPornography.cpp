#include "../Public/InputReportReasonPornography.h"


//begin namespace block
namespace COMMON
{

InputReportReasonPornography::InputReportReasonPornography()
{
	this->_ConstructorID = 777640226;
}
void InputReportReasonPornography::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputReportReasonPornography::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputReportReasonPornography::~InputReportReasonPornography()
{

}
}//end namespace block

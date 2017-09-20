#include "../Public/InputReportReasonPornography.h"


//begin namespace block
namespace COMMON
{

InputReportReasonPornography::InputReportReasonPornography()
{
	this->_ConstructorID = 584669486;
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
}
InputReportReasonPornography::~InputReportReasonPornography()
{

}
}//end namespace block

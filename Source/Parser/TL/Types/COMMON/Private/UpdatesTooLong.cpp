#include "../Public/UpdatesTooLong.h"


//begin namespace block
namespace COMMON
{

UpdatesTooLong::UpdatesTooLong()
{
	this->_ConstructorID = -484987010;
}
void UpdatesTooLong::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void UpdatesTooLong::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
UpdatesTooLong::~UpdatesTooLong()
{

}
}//end namespace block

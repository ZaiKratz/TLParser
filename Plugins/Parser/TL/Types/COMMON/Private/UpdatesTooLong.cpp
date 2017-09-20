#include "../Public/UpdatesTooLong.h"


//begin namespace block
namespace COMMON
{

UpdatesTooLong::UpdatesTooLong()
{
	this->_ConstructorID = 2125404131;
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
}
UpdatesTooLong::~UpdatesTooLong()
{

}
}//end namespace block

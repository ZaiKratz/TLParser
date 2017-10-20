#include "../Public/InputGeoPointEmpty.h"


//begin namespace block
namespace COMMON
{

InputGeoPointEmpty::InputGeoPointEmpty()
{
	this->_ConstructorID = -457104426;
}
void InputGeoPointEmpty::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputGeoPointEmpty::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
InputGeoPointEmpty::~InputGeoPointEmpty()
{
}
}//end namespace block

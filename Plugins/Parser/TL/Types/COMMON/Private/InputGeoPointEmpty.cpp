#include "../Public/InputGeoPointEmpty.h"


//begin namespace block
namespace COMMON
{

InputGeoPointEmpty::InputGeoPointEmpty()
{
	this->_ConstructorID = -702299676;
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
}
InputGeoPointEmpty::~InputGeoPointEmpty()
{

}
}//end namespace block

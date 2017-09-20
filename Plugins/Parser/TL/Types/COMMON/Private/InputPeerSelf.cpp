#include "../Public/InputPeerSelf.h"


//begin namespace block
namespace COMMON
{

InputPeerSelf::InputPeerSelf()
{
	this->_ConstructorID = -914448259;
}
void InputPeerSelf::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void InputPeerSelf::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
InputPeerSelf::~InputPeerSelf()
{

}
}//end namespace block

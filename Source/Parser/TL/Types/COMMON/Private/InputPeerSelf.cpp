#include "../Public/InputPeerSelf.h"


//begin namespace block
namespace COMMON
{

InputPeerSelf::InputPeerSelf()
{
	this->_ConstructorID = 2107670217;
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
	this->_Responded = true;
}
InputPeerSelf::~InputPeerSelf()
{

}
}//end namespace block

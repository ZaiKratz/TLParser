#include "../Public/AllStickersNotModified.h"


//begin namespace block
namespace MESSAGES
{

AllStickersNotModified::AllStickersNotModified()
{
	this->_ConstructorID = -1023252760;
}
void AllStickersNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void AllStickersNotModified::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
}
AllStickersNotModified::~AllStickersNotModified()
{

}
}//end namespace block

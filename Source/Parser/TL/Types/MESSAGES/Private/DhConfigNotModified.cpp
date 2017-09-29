#include "../Public/DhConfigNotModified.h"


//begin namespace block
namespace MESSAGES
{

DhConfigNotModified::DhConfigNotModified()
{
	this->_ConstructorID = -1058912715;
}

DhConfigNotModified::DhConfigNotModified(TArray<uint8>  random)
{
	this->_ConstructorID = -1058912715;
	this->random = random;
}
void DhConfigNotModified::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
	Writer.TGWriteBytes((unsigned char*)this->random.GetData(), this->random.Num());
}


void DhConfigNotModified::OnResponce(BinaryReader& Reader)
{
	random = Reader.TGReadBytes();
	this->_Responded = true;
}
DhConfigNotModified::~DhConfigNotModified()
{

}
}//end namespace block

#include "../Public/StickerSetInstallResultSuccess.h"


//begin namespace block
namespace MESSAGES
{

StickerSetInstallResultSuccess::StickerSetInstallResultSuccess()
{
	this->_ConstructorID = 946083368;
}
void StickerSetInstallResultSuccess::OnSend(BinaryWriter& Writer)
{
	Writer.WriteInt(this->_ConstructorID);
}


void StickerSetInstallResultSuccess::OnResponce(BinaryReader& Reader)
{
	{
	//pass
	}
	this->_Responded = true;
}
StickerSetInstallResultSuccess::~StickerSetInstallResultSuccess()
{

}
}//end namespace block

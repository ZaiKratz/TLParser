#pragma once
#include "Engine.h"

#include "../../../Types/Private/FileType.h"

//begin namespace block
namespace STORAGE
{
class FileMp3 : public PRIVATE::FileType
{
public:
	FileMp3();
	~FileMp3();
	virtual void OnSend(BinaryWriter& Writer) override;
	virtual void OnResponce(BinaryReader& Reader) override;

private:
};
} //end namespace block

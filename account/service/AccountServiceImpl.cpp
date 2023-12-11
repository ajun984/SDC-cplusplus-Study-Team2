//
// Created by eddi on 23. 12. 6.
//
#include "AccountServiceImpl.h"

#include <iostream>

AccountServiceImpl::AccountServiceImpl(std::shared_ptr<AccountRepository> accountRepository) : accountRepository(accountRepository) { }

bool AccountServiceImpl::regi(AccountRegisterRequest *request)
{
    std::cout << "회원가입" << std::endl;
    bool isRegisterSuccess = accountRepository->createAccount(request->toAccount());

    return isRegisterSuccess;

}

bool AccountServiceImpl::login(AccountLoginRequest *request)
{
    return accountRepository->checkAccount(request->getAccountId(), request->getPassword());
}
Rails.application.routes.draw do
  get 'page/index'
  get 'sensorie/new'
  get 'sensorie/create'
  get 'sensorie/index'
  get 'sensorie/edit'
  get 'sensorie/update'
  get 'sensorie/destroy'
  # For details on the DSL available within this file, see http://guides.rubyonrails.org/routing.html
  root to: 'page#index'
end

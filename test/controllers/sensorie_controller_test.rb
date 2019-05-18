require 'test_helper'

class SensorieControllerTest < ActionDispatch::IntegrationTest
  test "should get new" do
    get sensorie_new_url
    assert_response :success
  end

  test "should get create" do
    get sensorie_create_url
    assert_response :success
  end

  test "should get index" do
    get sensorie_index_url
    assert_response :success
  end

  test "should get edit" do
    get sensorie_edit_url
    assert_response :success
  end

  test "should get update" do
    get sensorie_update_url
    assert_response :success
  end

  test "should get destroy" do
    get sensorie_destroy_url
    assert_response :success
  end

end
